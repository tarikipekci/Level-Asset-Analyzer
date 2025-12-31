#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "EditorCollisionHelper.generated.h"

UENUM(BlueprintType)
enum class ECollisionComplexityResult : uint8
{
	Simple UMETA(DisplayName = "Simple"),
	Complex UMETA(DisplayName = "Complex"),
	SimpleAndComplex UMETA(DisplayName = "Simple And Complex"),
	UseProjectDefault UMETA(DisplayName = "Use Project Default"),
	Unknown UMETA(DisplayName = "Unknown")
};

UCLASS()
class LEVELASSETANALYZER_API UEditorCollisionHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Editor|Collision")
	static ECollisionComplexityResult GetStaticMeshCollisionComplexity(UStaticMesh* StaticMesh);
	
	UFUNCTION(BlueprintCallable, Category="Editor|Mesh")
	static int32 GetStaticMeshVertexCount(UStaticMesh* StaticMesh);
};
