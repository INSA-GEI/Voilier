#include <gui/choixcanal_screen/ChoixCanalView.hpp>

extern "C" {
#include "xbee.h"

void assert_failed(uint8_t *file, uint32_t line);
}

ChoixCanalView::ChoixCanalView()
{

}

void ChoixCanalView::setupScreen()
{
	ChoixCanalViewBase::setupScreen();
}

void ChoixCanalView::tearDownScreen()
{
	ChoixCanalViewBase::tearDownScreen();
}

void ChoixCanalView::buttonConnectClicked()
{
	//touchgfx_printf("Bouton demarrer appuye\n");
	XbeeStartRx();
	if (XbeeSetup(canalVoilier+0x80, canalVoilier) != XBEE_STATUS_SUCCESS) {
		assert_failed((uint8_t *) __FILE__, __LINE__);
	}
}

void ChoixCanalView::buttonUpClicked()
{
	touchgfx_printf("Bouton Up appuye\n");

	canalVoilier++;
	if (canalVoilier>7) canalVoilier=7;

	Unicode::snprintf(textCanalVoilierBuffer, TEXTCANALVOILIER_SIZE, "%d", canalVoilier);
	textCanalVoilier.invalidate();
}

void ChoixCanalView::buttonDownClicked()
{
	touchgfx_printf("Bouton Down appuye\n");

	canalVoilier--;
	if (canalVoilier<0) canalVoilier=0;

	Unicode::snprintf(textCanalVoilierBuffer, TEXTCANALVOILIER_SIZE, "%d", canalVoilier);
	textCanalVoilier.invalidate();
}
