from bson.json_util import dumps

def geojson_converter(data):
    geojson_data = {"type":"FeatureCollection", "features": []}
    print(data)
    if type(data) is list:
        geojson_data['features'] = data
    else:
        geojson_data['features'] = [data]
    print(geojson_data['features'])
    f = open("./output.geojson", 'w')
    f.write(dumps(geojson_data))
    f.close()
