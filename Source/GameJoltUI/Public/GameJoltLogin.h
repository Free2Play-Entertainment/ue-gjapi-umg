// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameJoltEnums.h"
#include "GameJoltLogin.generated.h"

class UButton;
class UEditableTextBox;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSuccessDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFailureDelegate, EGJErrors, Error);

/**
 * 
 */
UCLASS(Abstract)
class GAMEJOLTUI_API UGameJoltLogin : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditableTextBox* UserNameBox;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditableTextBox* UserTokenBox;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, OptionalWidget = true))
	UButton* LoginButton;

	/**
	 * Callback for Login
	 */
	UPROPERTY(BlueprintAssignable)
	FSuccessDelegate Success;

	/**
	 * Callback for Login
	 */
	UPROPERTY(BlueprintAssignable)
	FFailureDelegate OnFailed;

protected:

	UFUNCTION()
	void TextChanged(const FText& Text);

	/**
	 * Only call this, if you are not binding to the LoginButton
	 */
	UFUNCTION(BlueprintCallable)
	void Login();

	UFUNCTION()
	void OnFailure(EGJErrors Error);

	UFUNCTION()
	void OnSuccess();
};
