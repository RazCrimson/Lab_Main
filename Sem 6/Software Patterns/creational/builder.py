from typing import List, Tuple


class URLBuilder:
    def __init__(self):
        self._scheme = None
        self._domain = None
        self._port = None
        self._path = None
        self._query_parameters = {}

    def set_scheme(self, scheme: str):
        self._scheme = scheme
        return self

    def set_domain(self, domain: str):
        self._domain = domain
        return self

    def set_port(self, port: int):
        self._port = port
        return self

    def set_path(self, path: str):
        # This is a POC example. Process path segements with validations for RL cases
        self._path = path
        return self

    def set_query_parameter(self, key: str, value: str):
        self._query_parameters[key] = value
        return self

    def set_query_parameters(self, params: List[Tuple[str, str]]):
        for key, value in params:
            self._query_parameters[key] = value
        return self

    def build(self) -> str:
        if not self._scheme:
            raise ValueError("No scheme set")
        if not self._domain:
            raise ValueError("No domain set")
        if not self._port:
            raise ValueError("No port set")

        url = f"{self._scheme}://{self._domain}:{self._port}/"

        if self._path:
            url += self._path
        if self._query_parameters:
            url += "?"

        url += "&".join(f"{key}={value}" for key, value in self._query_parameters.items())

        return url


if __name__ == "__main__":
    url = (
        URLBuilder()
        .set_scheme("http")
        .set_domain("localhost")
        .set_port(8000)
        .set_path("random/path.html")
        .set_query_parameter("test", "example")
        .build()
    )
    print(url)
