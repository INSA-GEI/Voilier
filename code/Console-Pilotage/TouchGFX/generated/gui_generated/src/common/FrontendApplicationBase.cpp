/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include<platform/driver/lcd/LCD24bpp.hpp>
#include <gui/choixcanal_screen/ChoixCanalView.hpp>
#include <gui/choixcanal_screen/ChoixCanalPresenter.hpp>
#include <gui/rotationvoilier_screen/RotationVoilierView.hpp>
#include <gui/rotationvoilier_screen/RotationVoilierPresenter.hpp>
#include <gui/messages_screen/MessagesView.hpp>
#include <gui/messages_screen/MessagesPresenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_LANDSCAPE);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD24bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
}

/*
 * Screen Transition Declarations
 */

// ChoixCanal

void FrontendApplicationBase::gotoChoixCanalScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoChoixCanalScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoChoixCanalScreenNoTransitionImpl()
{
    touchgfx::makeTransition<ChoixCanalView, ChoixCanalPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// RotationVoilier

void FrontendApplicationBase::gotoRotationVoilierScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoRotationVoilierScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoRotationVoilierScreenNoTransitionImpl()
{
    touchgfx::makeTransition<RotationVoilierView, RotationVoilierPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Messages

void FrontendApplicationBase::gotoMessagesScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMessagesScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMessagesScreenNoTransitionImpl()
{
    touchgfx::makeTransition<MessagesView, MessagesPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
