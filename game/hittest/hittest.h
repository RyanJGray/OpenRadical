// STATUS: NOT STARTED

#ifndef GAME_HITTEST_HITTEST_H
#define GAME_HITTEST_HITTEST_H

typedef u8 vindex;

typedef struct {
	u8 Vertex1;
	u8 Vertex2;
	u8 Part;
	u8 Chunk;
	u8 Poly;
} AdjPoly;

typedef struct {
	s8 NumVertices;
	s8 x;
	s8 y;
	s8 z;
	float Norm[3];
	float d;
	vindex *pVertices;
	int NumAdjPolys;
	AdjPoly *pAdjPolys;
} ColPoly;

float hittestMoveCircleToPoint(float cx, float cy, float cr, float dx, float dy, float px, float py, float *hitnorm);
float hittestMoveCircleToLine(float cx, float cy, float cr, float dx, float dy, float ax, float ay, float bx, float by, float *hitnorm);
float hittestMoveCircleToCircle(float c1x, float c1y, float c1r, float dx, float dy, float c2x, float c2y, float c2r, float *HitNorm);
int hittestBoxBox(float *b1min, float *b1max, float *b2min, float *b2max);
int hittestLineBox(float *point, float *dir, float *bmin, float *bmax);
int hittestLineTri(float *point, float *dir, float *v1, float *v2, float *v3, float *hitpos, float *hitnorm);
int hittestLinePoly(float *point, float *dir, float DirSq, float MaxDistSq, float *pVertex, ColPoly *pPoly, boolean SingleSided, float *hitpos);
int hittestLineCyl(float cx, float cy, float cz, float cr, float ch, float dx, float dy, float dz, float px, float py, float pz, float *hitpos, float *hitnorm);
boolean HitTestLineCylinder(float *LinePoint, float *LineDirection, float *CylinderStart, float *CylinderEnd, float CylinderRadiusSquared, float *HitPos, float *HitNorm);
boolean HitTestLineSphere(float *LinePoint, float *LineDirection, float *SphereCenter, float SphereRadiusSquared, float *HitPos, float *HitNorm);
boolean HitTestLineBox(float *LinePoint, float *LineDirection, float *BoxMin, float *BoxMax, float *HitPos, float *HitNorm);
float HitTestDistancePointToLineSquared(float *Point, float *LinePoint, float *LineDirection, float *LineNearestPos);
float HitTestDistancePointToLineSegmentSquared(float *Point, float *LinePoint1, float *LinePoint2, float *LineNearestPos);
float HitTestDistanceLineSegmentToPlane(float *LinePoint1, float *LinePoint2, float *PlanePoint, float *PlaneNormal, float *LineNearestPos, float *PlaneNearestPos);
float HitTestDistanceLineSegmentToLineSegmentSquared(float *Line1Point1, float *Line1Point2, float *Line2Point1, float *Line2Point2, float *Line1NearestPos, float *Line2NearestPos);
boolean hittestDistGlass(float *point, float *dir, float maxdistsq, glasspointdef *glassPoints, int numPoints, float *hitpos, float *hitnorm);

#endif // GAME_HITTEST_HITTEST_H
