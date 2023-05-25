// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorToSpawn.h"
#include "Components/SphereComponent.h"

// Sets default values
AActorToSpawn::AActorToSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Creating Default Components
    SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

    // Attaching the Components and setting physics
    SphereComp->SetupAttachment(RootComponent);
    SphereComp->SetSimulatePhysics(true);
    SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

    StaticMeshComp->AttachToComponent(SphereComp, FAttachmentTransformRules::KeepRelativeTransform);

    // Setting the Sphere radius to be of a smaller size in line with the Static Mesh.
    SphereComp->SetSphereRadius(16.0f);

    // Setting the Static Mesh Scale and Location to fit the radius of the Sphere.
    StaticMeshComp->SetRelativeLocation(FVector(0.0, 0.0, 0.0f));
    StaticMeshComp->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

    // Using Constructor Helpers to set our Static Mesh Comp with a Sphere Shape.
    static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
    StaticMeshComp->SetStaticMesh(SphereMeshAsset.Object);

}

// Called when the game starts or when spawned
void AActorToSpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AActorToSpawn::DestroyActor()
{
}

void AActorToSpawn::Damaged()
{
}

// Called every frame
void AActorToSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

