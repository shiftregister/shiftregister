# 1|LINESTRING(8.9871812 50.0591294,8.4325862 49.1043102)

# sets of lines from each point to each point longX, latY (in csv is lat/long so we need to swop) 

import csv, sys

#epsilon=sys.float_info.epsilon
epsilon=0.01 # precision

#data = sys.argv[1]
#title = sys.argv[2]

def read_csv_file(filename):
    data = []
    for row in csv.reader(open(filename)):
        data.append(row)
    return data

# read in csv into dictionary of x/y

data=read_csv_file('MegP_Brandenburg,_Berlin.csv')

ylatitude    = []
xlongitude   = []
#print data
skip=0 # to skip the first line
for row in data:
    if skip>0:
        ylatitude.append(float(row[6]))
        xlongitude.append(float(row[5]))# for: http://www.megalithic.co.uk/topics.php?countries=1&kmldown=1
    skip+=1
    
# print ylatitude
cnt=0;
for x in range(len(xlongitude)):
    # connect point 0 to 1+, 1 to 2+ etc and write ID and LINESTRING
    for points in range(len(xlongitude)-1-x):
        print str(cnt)+"|LINESTRING("+str(xlongitude[x])+" "+str(ylatitude[x])+","+str(xlongitude[points+x+1])+" "+str(ylatitude[points+x+1])+")"
        cnt+=1

def isBetween(ax, ay, bx, by, cx, cy):
    crossproduct = (cy - ay) * (bx - ax) - (cx - ax) * (by - ay)
    if abs(crossproduct) > epsilon : return False   # (or != 0 if using integers)

    dotproduct = (cx - ax) * (bx - ax) + (cy - ay)*(by - ay)
    if dotproduct < 0 : return False

    squaredlengthba = (bx - ax)*(bx - ax) + (by - ay)*(by - ay)
    if dotproduct > squaredlengthba: return False

    return True

# this works - next step what straight lines run through several points
# or start with (furthest) points from say 0, anything on the way and so on...

# problem is that sites close to each other skew results - removed these

# cnt=0
# for x in range(len(xlongitude)):
#     # connect point 0 to 1+, 1 to 2+ etc and write ID and LINESTRING
#     for points in range(len(xlongitude)-1):
#         for between in range(len(xlongitude)-2):
#             if isBetween(xlongitude[x], ylatitude[x], xlongitude[points+1], ylatitude[points+1],xlongitude[between+2], ylatitude[between+2]) and x!=(points+1) and x!=(between+2) and (points+1)!=between+2:
# # and we don't ahve already in dict
#                 #                print "FOUND!"
# #                print x, points+1, between+2
#                 print str(cnt)+"|LINESTRING("+str(xlongitude[x])+" "+str(ylatitude[x])+","+str(xlongitude[points+1])+" "+str(ylatitude[points+1])+","+str(xlongitude[between+2])+" "+str(ylatitude[between+2])+")"
#                 cnt+=1

# how to take a line (eg. fukushima, chernobyl) and extend this in both directions?
