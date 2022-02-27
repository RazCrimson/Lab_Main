from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()

# Mock Database
db = {"users": {}}


class UserCredentials(BaseModel):
    username: str
    password: str


@app.post("/login")
def login(creds: UserCredentials):
    if creds.username in db["users"] and creds.password == db["users"][creds.username]["password"]:
        return "Logged In!"
    return "Invalid Credentials!"


@app.post("/register")
def register(creds: UserCredentials):
    if creds.username not in db["users"]:
        password = "".join(char.lower() for char in creds.password if char.isalpha())
        if len(password) != 6:
            return "Invalid Password size!"
        db["users"][creds.username] = {"password": password}
        return "Account Created!"
    return "Username taken!"


if __name__ == "__main__":
    import uvicorn

    uvicorn.run(app, host="0.0.0.0", port=8000)
