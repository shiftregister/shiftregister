# for kml file (kmz unzipped) from: http://www.zook.info/tld_map.html
# to be adapted for other kml

from pykml import parser
import sys
reload(sys)
sys.setdefaultencoding('utf8')


root = parser.fromstring(open('Downloads/doc.kml', 'r').read())
#print root.Document.Folder.Folder.Placemark.Point.coordinates # prints first one only
#print root
print root.Document.Folder[4].name # folder 4 is physical locations

for lenny in range(len(root.Document.Folder[4].Folder)): # this seems to work
    print root.Document.Folder[4].Folder[lenny].name+","+root.Document.Folder[4].Folder[lenny].Placemark.Point.coordinates 
