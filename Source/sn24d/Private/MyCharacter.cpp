// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyActor.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}



// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
    UGameInstance* game1 = GetWorld()->GetGameInstance();
    game = Cast<UMyGameInstance>(game1);

	FHttpModule& http = FHttpModule::Get();
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> req = http.CreateRequest();
	req->SetVerb(TEXT("GET"));
	req->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
	req->SetURL(TEXT("jke.pw/motd"));
	req->SetContentAsString(TEXT(""));
    req->OnProcessRequestComplete().BindLambda(
        // Here, we "capture" the 'this' pointer (the "&"), so our lambda can call this
        // class's methods in the callback.
        [&](
            FHttpRequestPtr pRequest,
            FHttpResponsePtr pResponse,
            bool connectedSuccessfully) mutable {

                if (connectedSuccessfully) {

                    // We should have a JSON response - attempt to process it.
                    resp(pResponse->GetContentAsString());
                }
                else {
                    switch (pRequest->GetStatus()) {
                    case EHttpRequestStatus::Failed_ConnectionError:
                        resp(TEXT("No connection."));
                    default:
                        resp(TEXT("Request failed."));
                    }
                }
        });

    // Finally, submit the request for processing
    req->ProcessRequest();
    resp(TEXT("Connecting..."));
    check(IsInGameThread());

	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	int i;
	for (i = 0; i < 1111; i++) {

        AActor* actor2 = GetWorld()->SpawnActor<AActor>(game->actor);

        actor2->SetActorLocation(
            FVector(FMath::RandRange(-1111, 1111), FMath::RandRange(-11111, 11111), 0));

	}
	Super::BeginPlay();

}

void AMyCharacter::resp(FString str) {
    game->text = str;
};

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

