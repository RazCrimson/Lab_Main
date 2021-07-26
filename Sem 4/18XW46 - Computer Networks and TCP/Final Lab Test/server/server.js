/*
A simple HTTP file server

Author: Raz Crimson(19PW08)
*/

const http = require('http');
const handlers = require("./handlers")

const PORT = 3000;

// Creating a server and listening at port 1800
http.createServer((req, res) => {

    var body = '';

    req.on('data', chunk => body += chunk)

    req.on('end', () => {
        req.body = body;

        const mode = req.method;
        const decodedURI = decodeURI(req.url);             // To handle URI encoded characters like %20

        switch (mode) {
            case 'GET': responseData = handlers.getHandler(req, res, decodedURI); break;
            case 'PUT': responseData = handlers.putHandler(req, res, decodedURI); break;
            case 'POST': responseData = handlers.postHandler(req, res, decodedURI); break;
            case 'DELETE': responseData = handlers.deleteHandler(req, res, decodedURI); break;
            default:
                responseData = JSON.stringify({ code: -1, message: "Invalid HTTP Method!"});
        }
        res.setHeader("content-length", `${responseData.length}`)
        res.write(responseData)
        res.end();
    })

}).listen(PORT);

console.log(`Server listening on port ${PORT}`);
