#include <gui/menu_screen/MenuView.hpp>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendApplication.hpp>

MenuView::MenuView()
{

}

void MenuView::setupScreen()
{
	MenuViewBase::setupScreen();
}

void MenuView::tearDownScreen()
{
	MenuViewBase::tearDownScreen();
}

void MenuView::scrollWheelUpdateItem(MenuContainer& item, int16_t itemIndex)
{
	item.setNumber(itemIndex);
}

void MenuView::ButtonOKClicked()
{
	switch (scrollWheel.getSelectedItem())
	{
	case 0:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoTestRotationPlateauScreenSlideTransitionEast();
		break;
	case 1:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoTestOrientationVoileScreenSlideTransitionEast();
		break;
	case 2:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoTestADCScreenSlideTransitionEast();
		break;
	case 3:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoTestUartScreenSlideTransitionEast();
		break;
	case 4:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoTestI2CSPIScreenSlideTransitionEast();
		break;
	case 5:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoTestGirouetteScreenSlideTransitionEast();
		break;
	case 6:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoTestCompletScreenSlideTransitionEast();
		break;
	default:
		break;
	}
	//else
		//	static_cast<FrontendApplication*>(Application::getInstance())->gotoTestUartScreenNoTransition();
}
