// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "MyGameInstance.h"

// Sets default values
AMyActor::AMyActor()
{

	//PrimaryActorTick.bCanEverTick = true;
	//mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	//RootComponent = mesh;



}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UGameInstance* game1 = GetWorld()->GetGameInstance();
	//if (game1) {
	//	UMyGameInstance* game = Cast<UMyGameInstance>(game1);
	//	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	//	mesh->SetStaticMesh(game->mesh);
	//	mesh->SetMaterial(0, game->mat);

	//}
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

