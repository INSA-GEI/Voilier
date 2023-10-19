//#include <new>
#include <gui/common/FrontendApplication.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
//#include <texts/TextKeysAndLanguages.hpp>
//#include <touchgfx/Texts.hpp>
//#include <touchgfx/hal/HAL.hpp>
//#include <platform/driver/lcd/LCD24bpp.hpp>
#include <gui/menu_screen/MenuView.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>
#include <gui/testrotationplateau_screen/TestRotationPlateauView.hpp>
#include <gui/testrotationplateau_screen/TestRotationPlateauPresenter.hpp>
#include <gui/testuart_screen/TestUartView.hpp>
#include <gui/testuart_screen/TestUartPresenter.hpp>
#include <gui/testi2cspi_screen/TestI2CSPIView.hpp>
#include <gui/testi2cspi_screen/TestI2CSPIPresenter.hpp>
#include <gui/testorientationvoile_screen/TestOrientationVoileView.hpp>
#include <gui/testorientationvoile_screen/TestOrientationVoilePresenter.hpp>
#include <gui/testadc_screen/TestADCView.hpp>
#include <gui/testadc_screen/TestADCPresenter.hpp>
#include <gui/testcomplet_screen/TestCompletView.hpp>
#include <gui/testcomplet_screen/TestCompletPresenter.hpp>
#include <gui/testgirouette_screen/TestGirouetteView.hpp>
#include <gui/testgirouette_screen/TestGirouettePresenter.hpp>

using namespace touchgfx;


FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
: FrontendApplicationBase(m, heap)
{

}
