#include "EditorCollisionHelper.h"
#include "PhysicsEngine/BodySetup.h"
#include "PhysicsEngine/PhysicsSettings.h"


class UPhysicsSettings;

ECollisionComplexityResult
UEditorCollisionHelper::GetStaticMeshCollisionComplexity(UStaticMesh* StaticMesh)
{
	if (!StaticMesh)
	{
		return ECollisionComplexityResult::Unknown;
	}

	UBodySetup* BodySetup = StaticMesh->GetBodySetup();
	if (!BodySetup)
	{
		StaticMesh->CreateBodySetup();
		BodySetup = StaticMesh->GetBodySetup();
	}

	if (!BodySetup)
	{
		return ECollisionComplexityResult::Unknown;
	}

	ECollisionTraceFlag TraceFlag = BodySetup->CollisionTraceFlag;

	// 🔹 Project Default Resolve
	if (TraceFlag == ECollisionTraceFlag::CTF_UseDefault)
	{
		ECollisionTraceFlag ProjectDefault =
			GetDefault<UPhysicsSettings>()->DefaultShapeComplexity;

		TraceFlag = ProjectDefault;
	}

	switch (TraceFlag)
	{
	case ECollisionTraceFlag::CTF_UseSimpleAsComplex:
		return ECollisionComplexityResult::Simple;

	case ECollisionTraceFlag::CTF_UseComplexAsSimple:
		return ECollisionComplexityResult::Complex;

	case ECollisionTraceFlag::CTF_UseSimpleAndComplex:
		return ECollisionComplexityResult::SimpleAndComplex;

	default:
		return ECollisionComplexityResult::Unknown;
	}
}

int32 UEditorCollisionHelper::GetStaticMeshVertexCount(UStaticMesh* StaticMesh)
{
	if (!StaticMesh || !StaticMesh->GetRenderData() || StaticMesh->GetRenderData()->LODResources.Num() == 0)
	{
		return 0;
	}

	return StaticMesh->GetRenderData()->LODResources[0].GetNumVertices();
}

