import os
import re

import matplotlib.pyplot as plt
import nltk
import numpy as np
import pandas as pd
from nltk.corpus import stopwords, wordnet
from nltk.stem import WordNetLemmatizer
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer

folder = os.path.dirname(__file__)
dataset = os.path.join(folder, "mammoreport.csv")
df = pd.read_csv(dataset)

# Remove unnecessary data
del df["Birads"]

documents = df.copy()
df.head()

### Converting to string of lowercase and striping spaces
df["Features"] = df["Features"].astype(str)
df["Features"] = df["Features"].str.lower()
df["Features"] = df["Features"].str.strip()
df.head()

### Removing punctuations
df["Features"] = df["Features"].apply(lambda text: re.sub(r"[^\w\s]", " ", text))
df.head()

### Removing stopwords from the data
nltk.download("stopwords")
df["Features"] = df["Features"].apply(
    lambda text: " ".join([word for word in text.split() if word not in stopwords.words("english")])
)
df.head()

### Lemmetizing the report data
nltk.download("wordnet")
nltk.download("omw-1.4")
nltk.download("punkt")
nltk.download("averaged_perceptron_tagger")


lemmatizer = WordNetLemmatizer()

tag_dict = {"J": wordnet.ADJ, "N": wordnet.NOUN, "V": wordnet.VERB, "R": wordnet.ADV}


def get_wordnet_pos(word):
    tag = nltk.pos_tag([word])[0][1][0].upper()
    return tag_dict.get(tag, wordnet.NOUN)


def lemmetizeText(text):
    sentences = []
    for sentence in nltk.sent_tokenize(text):
        sentences.append(" ".join([lemmatizer.lemmatize(w, get_wordnet_pos(w)) for w in nltk.word_tokenize(sentence)]))
    return "".join(sentences)


df.loc[:, "Features"] = df.Features.apply(lemmetizeText)
df.head()

### Generating Term-Document Matrix

# TfIdf
vectorizer = TfidfVectorizer()
frequencies = vectorizer.fit_transform(df["Features"]).toarray()


# vectorizer = CountVectorizer()
# word_frequencies = vectorizer.fit_transform(df['Features']).toarray()
# X = word_frequencies

terms = vectorizer.get_feature_names_out()
terms = terms.tolist()


def get_top_n_match_indices(word, n=5):
    final_word = word.lower()
    final_word = word.strip()
    if word not in terms:
        return None
    axis = terms.index(word)
    word_index = frequencies[:, axis]
    match_indices = np.argsort(word_index)
    top_matches = match_indices[-n:]
    return top_matches[::-1]


if __name__ == "__main__":
    term = "see"
    indices = get_top_n_match_indices(term)
    print(documents.iloc[indices, :])
