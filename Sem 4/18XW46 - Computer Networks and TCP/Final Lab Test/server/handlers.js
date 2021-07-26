const path = require('path');
const fs = require('fs');
const { ENOENT } = require('constants');  // Using ENOENT as indicator for Resource Not found


const mimeType = {
    '.ico': 'image/x-icon',
    '.html': 'text/html',
    '.js': 'text/javascript',
    '.json': 'application/json',
    '.css': 'text/css',
    '.png': 'image/png',
    '.jpg': 'image/jpeg',
    '.wav': 'audio/wav',
    '.mp3': 'audio/mpeg',
    '.svg': 'image/svg+xml',
    '.pdf': 'application/pdf',
    '.doc': 'application/msword',
    '.eot': 'appliaction/vnd.ms-fontobject',
    '.ttf': 'aplication/font-sfnt'
};

module.exports.postHandler = (req, res, decodedURI) => {
    res.setHeader('Content-type', 'application/json; charset=utf-8');
    const resourcePath = path.join('./', decodedURI);
    var responseData = '';

    if (fs.existsSync(resourcePath)) {
        fs.unlinkSync(resourcePath);
        fs.writeFileSync(resourcePath, req.body)
        res.statusCode = 201;
        responseData = JSON.stringify({ code: 0, message: `Successfully modified the resource at '${decodedURI}'` });
    }
    else {
        fs.writeFileSync(resourcePath, req.body)
        res.statusCode = 201;
        responseData = JSON.stringify({ code: 0, message: `Successfully created the resource at '${decodedURI}'` });
    }
    return responseData
}

module.exports.putHandler = (req, res, decodedURI) => {
    res.setHeader('Content-type', 'application/json; charset=utf-8');
    const resourcePath = path.join('./', decodedURI);
    var responseData = '';

    if (fs.existsSync(resourcePath)) {
        res.statusCode = 201;
        responseData = JSON.stringify({ code: ENOENT, message: `Resource at '${decodedURI}' already exists` });
    }
    else {
        fs.writeFileSync(resourcePath, req.body)
        res.statusCode = 201;
        responseData = JSON.stringify({ code: 0, message: `Successfully created the resource at '${decodedURI}'` });
    }
    return responseData
}


module.exports.deleteHandler = (req, res, decodedURI) => {
    res.setHeader('content-type', 'application/json; charset=utf-8');
    const resourcePath = path.join('./', decodedURI);
    var responseData = '';

    if (fs.existsSync(resourcePath)) {
        fs.unlinkSync(resourcePath);
        res.statusCode = 200;
        responseData = JSON.stringify({ code: 0, message: `Successfully deleted resource at '${decodedURI}'` });
    }
    else {
        res.statusCode = 404;
        responseData = JSON.stringify({ code: ENOENT, message: `Cannot find resource at '${decodedURI}' to delete!` });
    }
    return responseData
}

module.exports.getHandler = (req, res, decodedURI) => {
    const resourcePath = path.join('./', decodedURI);
    const contentType = req.headers['x-type'] == 'json' ? 'application/json' : 'text/html';
    const ifModifiedSince = Date.parse(req.headers['if-modified-since']) != NaN ? Date.parse(req.headers['if-modified-since']) : '';

    var responseData = '';

    if (!fs.existsSync(resourcePath)) {
        res.statusCode = 404;
        res.setHeader('content-type', 'application/json');
        responseData = JSON.stringify({ code: ENOENT, message: `The resource at '${decodedURI}' cant be located!` });
    }
    else {
        fsStat = fs.lstatSync(resourcePath)
        if (fsStat.isDirectory()) {
            res.statusCode = 200;

            const filesList = fs.readdirSync(resourcePath);

            // For JSON formatted responses and HTML responses
            var body = contentType == 'application/json' ? {} : '<ul>';

            // Generating Hyperlinks to other files
            filesList.forEach(element => {

                if (fs.statSync(path.join(resourcePath, element))) {
                    if (contentType == 'application/json')
                        body[element] = `${decodedURI.slice(-1) != '/' ? req.url + '/' : req.url}${element}`;
                    else
                        body += `<br/><li> <a href='${decodedURI.slice(-1) != '/' ? req.url + '/' : req.url}${element}'> ${element} </a></li>`
                }
            });

            if (contentType == 'application/json')
                responseData = JSON.stringify({ code: 0, message: `List of files at '${decodedURI}'`, data: body });

            else {
                if (req.path != '/')
                    body += `<br/><li> <a href='../'> ../ </a></li>`;

                body += "</ul>";
                responseData = `<h1>List of files at '${decodedURI}' : </h1>` + body;

                res.setHeader('content-type', 'text/html');
            }
        }

        else {
            if (ifModifiedSince == '' | ifModifiedSince <= Date.parse(fsStat.mtime)) {
                res.statusCode = 200;
                data = fs.readFileSync(resourcePath)

                const ext = path.parse(resourcePath).ext;
                if (mimeType[ext] != undefined)
                    res.setHeader('content-type', mimeType[ext]);
                else
                    res.setHeader('content-type', 'text/plain');
                    
                res.setHeader('last-modified', (new Date(fsStat.mtime)).toUTCString());
                responseData = data;

            }
            else {
                res.statusCode = 304;
                responseData = '';
            }
        }
    }
    return responseData;
}