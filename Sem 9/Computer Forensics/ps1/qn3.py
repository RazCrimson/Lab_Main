def extract_jpeg_images(docx_path):
    with open(docx_path, 'rb') as docx_file:
        content = docx_file.read()
        
    images = []
    start = 0
    end = 0
    while True:
        start = content.find(b'\xff\xd8\xff', end)
        if start == -1:
            break
        
        end = content.find(b'\xff\xd9', start)
        if end == -1:
            break
        
        image_data = content[start:end+2]
        images.append(image_data)
        
        end += 2
    return images


docx_file_path = 'Test.docx'
extracted_images = extract_jpeg_images(docx_file_path)

for i, image_data in enumerate(extracted_images):
    image_path = f'extracted_image_{i}.jpeg'
    with open(image_path, 'wb') as image_file:
        image_file.write(image_data)
    print(f'Saved image: {image_path}')
