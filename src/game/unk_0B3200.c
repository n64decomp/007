#include <ultra64.h>
#include "bondtypes.h"
#include "limits.h"

// rodata

/*
* Address: 0x7f0b3200
*/
f32 calculateLineIntersectionFactor(coord2d *start1, coord2d *end1, coord2d *start2, coord2d *end2)
{
    f32 deltaX = start2->f[1] - end2->f[1];
    f32 deltaY = end2->f[0] - start2->f[0];
    f32 intersectionFactor = (start2->f[1] - start1->f[1]) * deltaY + (start2->f[0] - start1->f[0]) * deltaX;
    f32 totalLineLength = (end1->f[1] - start1->f[1]) * deltaY + (end1->f[0] - start1->f[0]) * deltaX;

    if (totalLineLength == 0.0f)
    {
        return 1.0f;
    }

    intersectionFactor /= totalLineLength;

    if (intersectionFactor < 0.0f || intersectionFactor > 1.0f)
    {
        return 1.0f;
    }

    return intersectionFactor;
}


/*
* Address: 0x7F0B32D8
*/
f32 calculatePointToLineDistance(struct coord3d *point3D, coord2d *lineStart, coord2d *lineEnd)
{
    f32 projectedDistance;
    f32 perpendicularDistance;
    f32 distanceSquared;
    f32 deltaX;
    f32 deltaY;

    deltaX = lineEnd->x - point3D->y;
    deltaY = lineEnd->y - point3D->z;

    perpendicularDistance = deltaY * lineStart->x - deltaX * lineStart->y;
    projectedDistance = deltaX * lineStart->x + deltaY * lineStart->y;

    distanceSquared = (point3D->x - perpendicularDistance) * (point3D->x + perpendicularDistance);

    if (distanceSquared < 0.0f)
    {
        return FLT_MAX;
    }

    projectedDistance -= sqrtf(distanceSquared);

    if (projectedDistance < 0.0f)
    {
        if (projectedDistance * projectedDistance + perpendicularDistance * perpendicularDistance <= point3D->x * point3D->x)
        {
            return 0.0f;
        }

        return FLT_MAX;
    }

    return projectedDistance;
}


/*
* Address: 0x7f0b33dc
*/
f32 calculateNormalizedLineIntersection(coord3d *point3D, coord2d *lineStart, coord2d *lineEnd, coord2d *direction)
{
    f32 directionLength ;
    f32 tempCrossProduct;
    coord2d normalizedDir;
    f32 deltaY;
    f32 deltaX;
    f32 lineLength;
    f32 inverseLineLength ;
    f32 normalY;
    f32 normalX;
    f32 proj1;
    f32 proj2;
    f32 parallelLineStartY;
    f32 parallelLineStartX;
    f32 parallelLineEndY;
    f32 parallelLineEndX;
    f32 crossProductPoint;
    f32 crossProductStart;
    f32 crossProductEnd;
    f32 intersectionFactor;
    f32 intersectionFactorLineEnd;
    f32 startProjection;
    f32 endProjection;

    directionLength  = sqrtf(direction->x * direction->x + direction->y * direction->y);

    if (directionLength  == 0.0f)
    {
        return 1.0f;
    }

    normalizedDir.x = direction->x * (1.0f / directionLength );
    normalizedDir.y = direction->y * (1.0f / directionLength );

    deltaX = lineEnd->x - lineStart->x;
    deltaY = lineEnd->y - lineStart->y;

    lineLength = sqrtf(deltaX * deltaX + deltaY * deltaY);

    if (lineLength == 0.0f)
    {
        goto handlezero;
    }

    inverseLineLength  = 1.0f / lineLength;
    normalX = deltaY * inverseLineLength ;
    normalY = -deltaX * inverseLineLength ;

    proj1 = point3D->x * normalX;
    proj2 = point3D->x * normalY;

    if (proj1 * (point3D->y - lineStart->x) + proj2 * (point3D->z - lineStart->y) < 0.0f)
    {
        proj1 = -proj1;
        proj2 = -proj2;
    }

    parallelLineStartX = lineStart->x + proj1;
    parallelLineStartY = lineStart->y + proj2;
    parallelLineEndX = lineEnd->x + proj1;
    parallelLineEndY = lineEnd->y + proj2;

    crossProductStart = (direction->y * parallelLineStartX) - (parallelLineStartY * direction->x);
    crossProductPoint = (point3D->y * direction->y) - (point3D->z * direction->x);
    crossProductEnd = (direction->y * parallelLineEndX) - (parallelLineEndY * direction->x);

    if (crossProductEnd < crossProductStart)
    {
        coord2d *tmp;

        tempCrossProduct = crossProductStart;
        crossProductStart = crossProductEnd;
        crossProductEnd = tempCrossProduct;

        tmp = lineStart;
        lineStart = lineEnd;
        lineEnd = tmp;

        normalX = -normalX;
        normalY = -normalY;
    }

    if (crossProductEnd == crossProductStart)
    {
        intersectionFactor = calculatePointToLineDistance(point3D, &normalizedDir, lineStart);
        intersectionFactorLineEnd = calculatePointToLineDistance(point3D, &normalizedDir, lineEnd);

        if (intersectionFactorLineEnd < intersectionFactor)
        {
            intersectionFactor = intersectionFactorLineEnd;
        }
    }
    else if (crossProductEnd < crossProductPoint)
    {
handlezero:
        intersectionFactor = calculatePointToLineDistance(point3D, &normalizedDir, lineEnd);
    }
    else if (crossProductPoint < crossProductStart)
    {
        intersectionFactor = calculatePointToLineDistance(point3D, &normalizedDir, lineStart);
    }
    else
    {
        startProjection = normalX * (point3D->y - lineStart->x) + normalY * (point3D->z - lineStart->y);
        endProjection = normalX * (point3D->y + direction->x - lineStart->x) + normalY * (point3D->z + direction->y - lineStart->y);

        if (startProjection == endProjection)
        {
            return 1.0f;
        }

        intersectionFactor = (startProjection - point3D->x) * directionLength  / (startProjection - endProjection);
    }

    if (directionLength  < intersectionFactor)
    {
        return 1.0f;
    }

    if (intersectionFactor < 0.0f)
    {
        return 0.0f;
    }

    return (f32) intersectionFactor * (1.0f / directionLength );
}
