// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorToSpawn.generated.h"

UCLASS()
class PRUEBACREEKGAMES_API AActorToSpawn : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorToSpawn();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Life;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isDead;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Destroys Actor if its life is 0
	void DestroyActor();

	// Lowers Actor's life if it's been shot
	void Damaged();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
