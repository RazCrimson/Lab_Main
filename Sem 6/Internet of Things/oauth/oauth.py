import json
import os
import urllib.parse

import requests
from fastapi import Depends, FastAPI
from starlette.responses import RedirectResponse

app = FastAPI()

CURRENT_DIR = os.path.dirname(os.path.realpath(__file__))
TOKEN_FILE_PATH = f"{CURRENT_DIR}/token.json"
CLIENT_SECRET_PATH = f"{CURRENT_DIR}/secrets.json"


def get_credentials() -> dict:
    with open(CLIENT_SECRET_PATH) as credentials_file:
        credentials = json.load(credentials_file)
    return credentials


def get_access_token() -> str:
    token_details = {"access_token": ""}
    if os.path.exists(TOKEN_FILE_PATH):
        with open(TOKEN_FILE_PATH, "r") as token_file:
            token_details = json.load(token_file)
    return token_details["access_token"]


def get_id_token() -> str:
    if os.path.exists(TOKEN_FILE_PATH):
        with open(TOKEN_FILE_PATH, "r") as token_file:
            token_details = json.load(token_file)
    return token_details["id_token"]


@app.get("/")
def home():
    return RedirectResponse(url=f"/docs")


@app.get("/login")
def login(credentials: dict = Depends(get_credentials)):
    params = {
        "client_id": credentials["web"]["client_id"],
        "scope": "openid email profile",
        "response_type": "code",
        "redirect_uri": "http://127.0.0.1:8000/callback",
        "nonce": "raz",
    }
    encoded_params = urllib.parse.urlencode(params)
    url = f"https://accounts.google.com/o/oauth2/v2/auth?{encoded_params}"
    return RedirectResponse(url)


@app.get("/callback")
def google_callback(code: str, credentials: dict = Depends(get_credentials)):
    data = {
        "code": code,
        "client_id": credentials["web"]["client_id"],
        "client_secret": credentials["web"]["client_secret"],
        "redirect_uri": "http://127.0.0.1:8000/callback",
        "grant_type": "authorization_code",
    }
    response = requests.post("https://oauth2.googleapis.com/token", data=data).json()
    with open(TOKEN_FILE_PATH, "w+") as token_file:
        token_file.write(json.dumps(response))

    return response


@app.get("/get_token_info")
def get_token_info(id_token: str = Depends(get_id_token)):
    params = {"id_token": id_token}
    response = requests.get("https://oauth2.googleapis.com/tokeninfo", params=params)
    return response.json()


@app.get("/get_user_info")
def get_user_info(access_token: str = Depends(get_access_token)):
    headers = {"Authorization": f"Bearer {access_token}"}
    response = requests.get("https://www.googleapis.com/oauth2/v1/userinfo?alt=json", headers=headers)
    return response.json()


@app.get("/logout")
def logout(access_token: str = Depends(get_access_token)):
    params = {"token": access_token}
    headers = {"content-type": "application/x-www-form-urlencoded"}
    response = requests.get("https://oauth2.googleapis.com/revoke", params, headers=headers)
    return response.json()


if __name__ == "__main__":
    # Please visit http://localhost:8000/login to initiate the oauth procedure

    import uvicorn

    uvicorn.run(app)
