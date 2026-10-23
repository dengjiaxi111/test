"""Pause helper: derive uphill exits from the accepted path, without speed regions."""
import math


def uphill_exits(points, regions):
    def cross(a, b):
        return a[0]*b[1]-a[1]*b[0]

    def inside(poly, q):
        signs=[cross((b[0]-a[0],b[1]-a[1]),(q[0]-a[0],q[1]-a[1]))
               for a,b in zip(poly,poly[1:]+poly[:1])]
        return not (any(x>1e-9 for x in signs) and any(x<-1e-9 for x in signs))

    exits=[]
    for region in regions:
        if region['type']!='slope':
            continue
        poly=region['geometry']['polygon']
        yaw=math.radians(region['attributes']['uphill_yaw_deg'])
        up=(math.cos(yaw),math.sin(yaw))
        arc=0.
        for a,b in zip(points,points[1:]):
            v=(b[0]-a[0],b[1]-a[1]);length=math.hypot(*v)
            if length<1e-9:
                continue
            if v[0]*up[0]+v[1]*up[1]>0:
                for c,d in zip(poly,poly[1:]+poly[:1]):
                    w=(d[0]-c[0],d[1]-c[1]);det=cross(v,w)
                    if abs(det)<1e-10:
                        continue
                    delta=(c[0]-a[0],c[1]-a[1])
                    t=cross(delta,w)/det;u=cross(delta,v)/det
                    if 0<=t<=1 and 0<=u<=1:
                        q0=(a[0]+v[0]*(t-1e-6),a[1]+v[1]*(t-1e-6))
                        q1=(a[0]+v[0]*(t+1e-6),a[1]+v[1]*(t+1e-6))
                        if inside(poly,q0) and not inside(poly,q1):
                            exits.append(arc+t*length)
            arc+=length
    return sorted(set(exits))
