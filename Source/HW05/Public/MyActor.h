// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector2D start;
	int32_t EventCount = 0;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void move();
	int32_t step();
	void createEvent(const int32_t& Probability);
	float distance(const FVector2D& a, const FVector2D& b);
	void AddFVector2DArray(const int32_t& a, const int32_t& b);
	void AddFVector2DArray(const FVector2D& a);
};
