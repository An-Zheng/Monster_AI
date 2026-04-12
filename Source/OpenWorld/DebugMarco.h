#pragma once
#include "DrawDebugHelpers.h"
#define DEBUG_SPHERE(loaction) if (GetWorld()) DrawDebugSphere(GetWorld(), loaction, 25.f, 12, FColor::Red, true, 30.f );
#define DEBUG_SPHERE_SINGLE_FRAME(loaction) if (GetWorld()) DrawDebugSphere(GetWorld(), loaction, 25.f, 12, FColor::Red, false, -1.f);
#define DEBUG_SPHERE_COLOR(loaction, color) if (GetWorld()) DrawDebugSphere(GetWorld(), loaction, 25.f, 12, color, true, 30.f );
#define DEBUG_BOX_COLOR(loaction, color) if (GetWorld()) DrawDebugBox(GetWorld(), loaction, FVector(100.0f, 100.0f, 100.0f), GetActorQuat(), color, true, -1.0f, 0, 5.0f );
#define DEBUG_BOX_COLOR_SINGLE_FRAME(loaction, color) if (GetWorld()) DrawDebugBox(GetWorld(), loaction, FVector(100.0f, 100.0f, 100.0f), GetActorQuat(), color, false, -1.0f, 0, 5.0f );

#define DEBUG_LINE(startLocation, endLocation) if (GetWorld()) DrawDebugLine(GetWorld(), startLocation, endLocation , FColor::Red, true, -1.0f, 0, 1.0f);
#define DEBUG_LINE_SINGLE_FRAME(startLocation, endLocation) if (GetWorld()) DrawDebugLine(GetWorld(), startLocation, endLocation , FColor::Red, false, -1.0f, 0, 1.0f);
#define DEBUG_VECTOR(startLocation, endLocation) if (GetWorld()) \
{\
	DrawDebugLine(GetWorld(), startLocation, endLocation , FColor::Red, true, -1.0f, 0, 1.0f);\
	DrawDebugPoint(GetWorld(), endLocation, 15.0f, FColor::Red, true);\
}


#define DEBUG_VECTOR_SINGLE_FRAME(startLocation, endLocation) if (GetWorld()) \
{\
	DrawDebugLine(GetWorld(), startLocation, endLocation , FColor::Red, false, -1.0f, 0, 1.0f);\
	DrawDebugPoint(GetWorld(), endLocation, 15.0f, FColor::Red, false);\
}
