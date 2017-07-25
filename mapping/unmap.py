import sys
reload(sys)
sys.setdefaultencoding('utf8')

# data is from https://raw.githubusercontent.com/52vis/2016-15/master/sites.json


import json
from pprint import pprint
json_data=open('sites.json')
jdata = json.load(json_data)
#jdata = json.load('{"site": "locations:"}')
#pprint (jdata)
x=0
for jdatas in jdata:
    if (jdatas['locations']!=[]):
        if (jdatas['locations'][0]['latitude']!=None):
            print"# | "+(jdatas['site']['name']),
            print "|",
            print(jdatas['locations'][0]['latitude']),
            print "|",
            print(jdatas['locations'][0]['longitude']),
            print "|",
            print
            x+=1
json_data.close()
