from bson.json_util import dumps

OUTPUT_PATH = "./output.geojson"

def geojson_converter(data, file_path=OUTPUT_PATH):
    geojson_data = {"type":"FeatureCollection", "features": []}
    if type(data) is list:
        geojson_data['features'] = data
    else:
        geojson_data['features'] = [data]
    f = open(file_path, 'w')
    f.write(dumps(geojson_data))
    f.close()
    print(len(geojson_data['features']), " written to ", file_path)
