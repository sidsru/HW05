// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

TArray<FVector2D> path;

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	move();
	float dist = distance(path[0], path[path.Num()-1]);
	UE_LOG(LogTemp, Log, TEXT("Distance from All point: %f\n"), dist);
	UE_LOG(LogTemp, Log, TEXT("Event: %d\n"), EventCount);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32_t AMyActor::step()
{
	return FMath::RandRange(0, 1);
}
void AMyActor::createEvent(const int32_t& Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!\n"));
		EventCount++;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered\n"));
	}

}

float AMyActor::distance(const FVector2D& a, const FVector2D& b)
{
	return FMath::Sqrt(FMath::Pow(b.X - a.X, 2) + FMath::Pow(b.Y - a.Y, 2));
}

void AMyActor::AddFVector2DArray(const int32_t& a, const int32_t& b)
{
	path.Push(FVector2D(a, b));
}

void AMyActor::AddFVector2DArray(const FVector2D& a)
{
	path.Push(FVector2D(a));
}

void AMyActor::move()
{
	start = FVector2D(0, 0);
	AddFVector2DArray(start);
	for (int32 i = 1; i <= 10; i++)
	{
		start.X += step();
		start.Y += step();
		AddFVector2DArray(start);
		float dist = distance(path[i - 1], path[i]);
		UE_LOG(LogTemp, Log, TEXT("x: %f y: %f\n"), start.X, start.Y);
		UE_LOG(LogTemp, Log, TEXT("Distance from previous point: %f\n"), dist);
		createEvent(50);
	}
}

