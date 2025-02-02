﻿// Copyright (c) 2022 Jonas Reich

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"

#include "JsonLibrary.generated.h"

USTRUCT(BlueprintType)
struct FOUUJsonLibraryObjectFilter
{
	GENERATED_BODY()
public:
	// Exclude object properties to objects of these classes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UClass*> ExcludeClasses;

	// At which depth of nested sub-objects the export should stop
	// Limit of 0 means no nested UObjects are serialized,
	// a limit of 1 means only the first nested objects are serialized, etc.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SubObjectDepthLimit = 3;
};

UCLASS()
class UOUUJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * Create a json string from an objects properties.
	 * Parses all properties down to the limit/filter settings provided in SubObjectFilter.
	 */
	UFUNCTION(BlueprintCallable)
	static FString UObjectToJsonString(
		UObject* Object,
		FOUUJsonLibraryObjectFilter SubObjectFilter,
		int64 CheckFlags = 0,
		int64 SkipFlags = 0);

	UFUNCTION(BlueprintCallable)
	static bool JsonStringToUObject(UObject* Object, FString String, int64 CheckFlags = 0, int64 SkipFlags = 0);
};
