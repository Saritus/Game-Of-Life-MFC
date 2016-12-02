
// GoLDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "XUnzip.h"
#include "GoL.h"
#include "GoLDlg.h"
#include "afxdialogex.h"
#include "Cell.h"
#include "Field.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGoLDlg-Dialogfeld

CGoLDlg::CGoLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGoLDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGoLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGoLDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CGoLDlg-Meldungshandler

int m_zustand;
struct zustandstabelle{
	int naechster_zustand;
	int aktion;
} m_tabelle[23][23] = {
	/*0*/       /*1*/       /*2*/       /*3*/       /*4*/       /*5*/       /*6*/       /*7*/       /*8*/       /*9*/       /*10*/      /*11*/      /*12*/      /*13*/      /*14*/      /*15*/      /*16*/      /*17*/      /*18*/      /*19*/      /*20*/      /*21*/      /*22*/
	/*0*/{ { -1, -1 }, { +1, 11 }, { -1, -1 }, { +3, 12 }, { +4, +1 }, { -1, -1 }, { +6, +2 }, { +7, +2 }, { -1, -1 }, { +9, +5 }, { -1, -1 }, { 11, +6 }, { 12, +2 }, { 13, +7 }, { -1, -1 }, { 15, +8 }, { 16, +2 }, { 17, +9 }, { -1, -1 }, { 19, 10 }, { 20, +2 }, { 21, +1 }, { 22, +8 } },
	/*1*/{ { +4, 15 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*2*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +7, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*3*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 20, 23 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*4*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +6, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*5*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +0, +4 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*6*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 11, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*7*/{ { +1, 17 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*8*/{ { -1, -1 }, { -1, -1 }, { +3, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*9*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 12, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*10*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 16, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*11*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 15, 13 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 19, 14 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*12*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +5, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +5, +0 }, { -1, -1 } },
	/*13*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +0, 16 }, { +8, +3 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 13, 21 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 17, 21 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +9, 19 }, { -1, -1 }, { -1, -1 } },
	/*14*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 10, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*15*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 21, 20 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*16*/{ { -1, -1 }, { +2, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*17*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { +0, 18 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*18*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 14, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*19*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +0, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +0, 22 } },
	/*20*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 18, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*21*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { +0, 22 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	/*22*/{ { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 22, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 22, +0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } } };


BOOL CGoLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CPaintDC dc(this);
	anim = false;
	logoanim = true;
	logodrag = true;
	m_zustand = 0;
	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	feld.breite = 14;
	feld.hoehe = 9;
	feld.feld_fuellen_random(30);

	// Hintergrund

	//     CSprite hintergrund;
	if (!hintergrund.Load("Creep.bmp", CSize(1515, 995))) {
		AfxMessageBox(L"konnte Creep.bmp nicht laden");
		OnCancel();
	}
	hintergrund.SetZ(0);
	hintergrund.SetSpriteNumber(0, 0);

	//     CSprite black;
	if (!black.Load("black.bmp")) {
		AfxMessageBox(L"konnte black.bmp nicht laden");
		OnCancel();
	}
	black.SetZ(1);
	black.SetPosition(1415, 0);

	//     CSprite logo;
	if (!logo.Load("Logo2.bmp", CSize(200, 200))) {
		AfxMessageBox(L"konnte logo.bmp nicht laden");
		OnCancel();
	}
	logo.SetZ(40);
	logo.SetSpriteNumber(0, 0);
	logo.SetPosition(1415, 0);

	// Spielfeld

	//     CSprite baneling[14*9];
	if (!baneling[0].Load("Baneling.bmp", CSize(100, 100))) {
		AfxMessageBox(L"konnte Unburrow.bmp nicht laden");
		OnCancel();
	}
	baneling[0].SetZ(20);
	for (int i = 0; i < feld.breite; i++) {
		for (int j = 0; j < feld.hoehe; j++) {
			baneling[i + feld.breite*j] = baneling[0];
			baneling[i + feld.breite*j].SetSpriteNumber(feld.field[i][j].animation, 0);
			baneling[i + feld.breite*j].SetPosition((101 * i) % (101 * feld.breite), (105 * j));
		}
	}

	// Menü
	
	//     CSprite button[7];
	if (!button[0].Load("Button_named.bmp", CSize(298, 51))) {
		AfxMessageBox(L"konnte Button_named.bmp nicht laden");
		OnCancel();
	}
	button[0].SetZ(55);
	button[0].SetAlpha(0.0f);
	button[4] = button[3] = button[2] = button[1] = button[0];
	if (!button[5].Load("Button small named.bmp", CSize(150, 51))) {
		AfxMessageBox(L"konnte Button small named.bmp nicht laden");
		OnCancel();
	}
	button[5].SetZ(55);
	button[5].SetAlpha(0.0f);
	button[6] = button[5];

	button[0].SetPosition(559, 1000);
	button[0].SetSpriteNumber(0, 0);
	button[1].SetPosition(559, 1000);
	button[1].SetSpriteNumber(0, 1);
	button[2].SetPosition(559, 1000);
	button[2].SetSpriteNumber(0, 3);
	button[3].SetPosition(559, 1000);
	button[3].SetSpriteNumber(0, 5);
	button[4].SetPosition(559, 1000);
	button[4].SetSpriteNumber(0, 4);
	button[5].SetPosition(559, 1000);
	button[5].SetSpriteNumber(0, 0);
	button[6].SetPosition(708, 1000);
	button[6].SetSpriteNumber(1, 0);

	//    CSprite menue;
	if (!menue.Load("Menue.bmp")) {
		AfxMessageBox(L"konnte Menue.bmp nicht laden");
		OnCancel();
	}
	menue.SetZ(50);
	menue.SetPosition(469, 1000);
	menue.SetAlpha(0.0f);

	//     CSprite menue_button;
	if (!menue_button.Load("Menue button.bmp", CSize(76, 42))) {
		AfxMessageBox(L"konnte Menue button.bmp nicht laden");
		OnCancel();
	}
	menue_button.SetZ(50);
	menue_button.SetPosition(1537, 917);

	// Option
	
	//     CSprite option;
	if (!option.Load("Optionen.bmp")) {
		AfxMessageBox(L"konnte Optionen.bmp nicht laden");
		OnCancel();
	}
	option.SetZ(40);
	option.SetPosition(417, 1000);
	option.SetAlpha(0.0f);
	
	//     CSprite o_accept;
	if (!o_accept.Load("Ok Abbrechen button.bmp", CSize(133, 25))) {
		AfxMessageBox(L"konnte Ok Abbrechen button.bmp nicht laden");
		OnCancel();
	}
	o_accept.SetZ(50);
	o_accept.SetSpriteNumber(0, 0);
	o_accept.SetPosition(464, 1000);
	o_accept.SetAlpha(0.0f);

	//     CSprite o_cancel;
	if (!o_cancel.Load("Ok Abbrechen button.bmp", CSize(133, 25))) {
		AfxMessageBox(L"konnte Ok Abbrechen button.bmp nicht laden");
		OnCancel();
	}
	o_cancel.SetZ(50);
	o_cancel.SetSpriteNumber(1, 0);
	o_cancel.SetPosition(819, 1000);
	o_cancel.SetAlpha(0.0f);

	//     CSprite checkbox[2];
	if (!checkbox[0].Load("check button.bmp", CSize(27, 26))) {
		AfxMessageBox(L"konnte check button.bmp nicht laden");
		OnCancel();
	}
	checkbox[0].SetZ(55);
	checkbox[0].SetSpriteNumber(0, 1);
	checkbox[0].SetAlpha(0.0f);
	checkbox[1] = checkbox[0];
	checkbox[0].SetPosition(498, 1000);
	checkbox[1].SetPosition(498, 1000);
	
	//     CSprite checkboxtext[2];
	if (!checkboxtext[0].Load("check text.bmp", CSize(170, 28))) {
		AfxMessageBox(L"konnte check button.bmp nicht laden");
		OnCancel();
	}
	checkboxtext[0].SetZ(54);
	checkboxtext[0].SetAlpha(0.0f);
	checkboxtext[1] = checkboxtext[0];
	checkboxtext[0].SetSpriteNumber(0, 0);
	checkboxtext[1].SetSpriteNumber(0, 1);
	checkboxtext[0].SetPosition(538, 1000);
	checkboxtext[1].SetPosition(538, 1000);

	//     CSlider slider;
	slider.SetZ(65);
	slider.SetPosition(497, 1000);
	slider.SetAlpha(0.0f);

	// Info	
	
	//     CSprite info_button;
	if (!info_button.Load("Help button.bmp", CSize(42, 43))) {
		AfxMessageBox(L"konnte Help button.bmp nicht laden");
		OnCancel();
	}
	info_button.SetZ(50);
	info_button.SetPosition(1496, 917);

	//     CSprite info;
	if (!info.Load("About.bmp")) {		// Option.bmp auswechseln
		AfxMessageBox(L"konnte Optionen.bmp nicht laden");
		OnCancel();
	}
	info.SetZ(40);
	info.SetPosition(417, 1000);
	info.SetAlpha(0.0f);

	//     CSprite i_accept;
	if (!i_accept.Load("Ok Abbrechen button.bmp", CSize(133, 25))) {
		AfxMessageBox(L"konnte Ok Abbrechen button.bmp nicht laden");
		OnCancel();
	}
	i_accept.SetZ(50);
	i_accept.SetSpriteNumber(0, 0);
	i_accept.SetPosition(464, 1000);
	i_accept.SetAlpha(0.0f);

	//     CSprite i_cancel;
	if (!i_cancel.Load("Ok Abbrechen button.bmp", CSize(133, 25))) {
		AfxMessageBox(L"konnte Ok Abbrechen button.bmp nicht laden");
		OnCancel();
	}
	i_cancel.SetZ(50);
	i_cancel.SetSpriteNumber(1, 0);
	i_cancel.SetPosition(819, 1000);
	i_cancel.SetAlpha(0.0f);

	// Save and Load
	
	//     CSprite files[3];
	if (!files[0].Load("file button named.bmp", CSize(152, 82))) {
		AfxMessageBox(L"konnte file button named.bmp nicht laden");
		OnCancel();
	}
	files[0].SetZ(52);
	files[0].SetAlpha(0.0f);
	files[2] = files[1] = files[0];
	files[0].SetPosition(467, 1000);
	files[0].SetSpriteNumber(0, 0);
	files[1].SetPosition(631, 1000);
	files[1].SetSpriteNumber(1, 0);
	files[2].SetPosition(795, 1000);
	files[2].SetSpriteNumber(2, 0);

	//     CSprite saveload;
	if (!saveload.Load("Optionen.bmp")) {	// Option.bmp auswechseln
		AfxMessageBox(L"konnte Optionen.bmp nicht laden");
		OnCancel();
	}
	saveload.SetZ(40);
	saveload.SetPosition(417, 1000);
	saveload.SetAlpha(0.0f);

	//     CSprite sl_accept;
	if (!sl_accept.Load("Ok Abbrechen button.bmp", CSize(133, 25))) {
		AfxMessageBox(L"konnte Optionen.bmp nicht laden");
		OnCancel();
	}
	sl_accept.SetZ(50);
	sl_accept.SetSpriteNumber(0, 0);
	sl_accept.SetPosition(464, 1000);
	sl_accept.SetAlpha(0.0f);

	//     CSprite sl_cancel;
	if (!sl_cancel.Load("Ok Abbrechen button.bmp", CSize(133, 25))) {
		AfxMessageBox(L"konnte Optionen.bmp nicht laden");
		OnCancel();
	}
	sl_cancel.SetZ(50);
	sl_cancel.SetSpriteNumber(1, 0);
	sl_cancel.SetPosition(819, 1000);
	sl_cancel.SetAlpha(0.0f);
	
	
	
	
	
	
	
	// Insert
	
	buffer.Load("Creep.bmp");

	list.SetWorkspace(&buffer);
	list.Insert(&(slider.slider));
	list.Insert(&(slider.line));
	list.Insert(&(slider.number));
	list.Insert(&menue_button);
	list.Insert(&info_button);
	list.Insert(&info);
	list.Insert(&o_accept);
	list.Insert(&o_cancel);
	list.Insert(&sl_accept);
	list.Insert(&sl_cancel);
	list.Insert(&i_accept);
	list.Insert(&i_cancel);
	list.Insert(&saveload);
	list.Insert(&checkbox[0]);
	list.Insert(&checkbox[1]);
	list.Insert(&checkboxtext[0]);
	list.Insert(&checkboxtext[1]);
	list.Insert(&files[0]);
	list.Insert(&files[1]);
	list.Insert(&files[2]);
	list.Insert(&option);
	list.Insert(&button[0]);
	list.Insert(&button[1]);
	list.Insert(&button[2]);
	list.Insert(&button[3]);
	list.Insert(&button[4]);
	list.Insert(&button[5]);
	list.Insert(&button[6]);
	list.Insert(&menue);
	for (int i = 0; i < feld.breite; i++) {
		for (int j = 0; j < feld.hoehe; j++) {
			list.Insert(&baneling[i + feld.breite*j]);
		}
	}
	list.Insert(&logo);
	list.Insert(&black);
	list.Insert(&hintergrund);
	captured = NULL;
	SetWindowPos(NULL, 0, 0, 1631, 1000, SWP_NOMOVE);
	SetTimer(1, 50, NULL);
	list.RedrawAll(&dc, 0, 0);

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CGoLDlg::OnPaint()
{
	CPaintDC dc(this); // Gerätekontext zum Zeichnen

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		list.RedrawAll(&dc, 0, 0);
		CDialogEx::OnPaint();
	}
}

HCURSOR CGoLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGoLDlg::OnTimer(UINT_PTR nIDEvent)
{	
	static int l = 0;
	static int p = 0;
	static int backg[20] = { 0, 1, 2, 3, 4, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 4, 3, 2, 1, 0 };
	CClientDC dc(this);
	CPoint pos;
	if ((nIDEvent == 1) && logoanim) {
		logo.SetSpriteNumber(0, p);
		p++; p = (p % 18);
	}
	if ((nIDEvent == 2) && anim) {
		for (int i = 0; i < feld.breite; i++) {
			for (int j = 0; j < feld.hoehe; j++) {
				baneling[i + feld.breite*j].SetSpriteNumber((feld.field[i][j].animation), l);
			}
		}
		hintergrund.SetSpriteNumber(backg[l], 0);
		l++;
		if (l == 4) {
			feld.next_life();
			l = 0;
		}
	}
	else {
		
	}

	

	list.Update(&dc, 0, 0);

	/*CString string;
	for (int i = 0; i < feld.breite; i++) {
		for (int j = 0; j < feld.hoehe; j++) {
			pos = baneling[i + feld.breite*j].GetPos();
			string.Format(L"%d", feld.field[i][j].life);
			dc.TextOut(pos.x+20, pos.y+20, string);
		}
	}*/

	AnimEngine(0);

	CDialogEx::OnTimer(nIDEvent);
}

void CGoLDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	CSprite* hit = list.HitTest(point);
	if (hit == &logo) {
		captured = hit;    
		mousePos = point;
	}
	else if (hit == &slider.slider) {
		captured = hit;
	}

	CDialogEx::OnRButtonDown(nFlags, point);
}

void CGoLDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	int offset;
	CPoint moveto;
	CClientDC dc(this);
	if (logodrag && (captured == &logo) && (nFlags & MK_RBUTTON)) {
		offset = point.y - mousePos.y;
		moveto.y = captured->GetPos().y + offset;
		logo.SetPosition(1415, moveto.y);
		mousePos = point;
	}
	else if (logodrag && (captured == &logo) && (nFlags & MK_LBUTTON)) {
		offset = point.y - mousePos.y;
		moveto.y = captured->GetPos().y + offset;
		logo.SetPosition(1415, moveto.y);
		mousePos = point;
	}
	else if ((captured == &slider.slider) && (nFlags & MK_LBUTTON)) {
		if (slider.GetCurrent() != slider.SetCurrent(((point.x - 497) / 15))) {
			if (slider.GetCurrent()) {
				KillTimer(2);
				SetTimer(2, slider.GetTime(), NULL);
			}
			else {
				KillTimer(2);
			}
		}
	}
	else if ((captured == &slider.slider) && (nFlags & MK_RBUTTON)) {
		if (slider.GetCurrent() != slider.SetCurrent(((point.x - 497) / 15))) {
			if (slider.GetCurrent()) {
				KillTimer(2);
				SetTimer(2, slider.GetTime(), NULL);

			}
			else {
				KillTimer(2);
			}
		}
	}
	else
	{
		captured = NULL;
		// uncapture sprite    
		CSprite* hit = list.HitTest(point);

		// Allgemein
		if (hit == &menue_button)
			menue_button.SetSpriteNumber(0, 1);
		else
			menue_button.SetSpriteNumber(0, 0);
		if (hit == &info_button)
			info_button.SetSpriteNumber(1, 0);
		else
			info_button.SetSpriteNumber(0, 0);

		// Info
		if (m_zustand == 2) {
			if (hit == &i_accept)
				i_accept.SetSpriteNumber(0, 1);
			else
				i_accept.SetSpriteNumber(0, 0);
			if (hit == &i_cancel)
				i_cancel.SetSpriteNumber(1, 1);
			else
				i_cancel.SetSpriteNumber(1, 0);
		}

		// Menü
		else if (m_zustand == 5) {
			if (hit == &button[0]) {
				if (anim) button[0].SetSpriteNumber(1, 2);
				else button[0].SetSpriteNumber(1, 0);
			}
			else {
				if (anim) button[0].SetSpriteNumber(0, 2);
				else button[0].SetSpriteNumber(0, 0);
			}
			if (hit == &button[1])
				button[1].SetSpriteNumber(1, 1);
			else
				button[1].SetSpriteNumber(0, 1);
			if (hit == &button[2])
				button[2].SetSpriteNumber(1, 3);
			else
				button[2].SetSpriteNumber(0, 3);
			if (hit == &button[3])
				button[3].SetSpriteNumber(1, 5);
			else
				button[3].SetSpriteNumber(0, 5);
			if (hit == &button[4])
				button[4].SetSpriteNumber(1, 4);
			else
				button[4].SetSpriteNumber(0, 4);
			if (hit == &button[5])
				button[5].SetSpriteNumber(0, 1);
			else
				button[5].SetSpriteNumber(0, 0);
			if (hit == &button[6])
				button[6].SetSpriteNumber(1, 1);
			else
				button[6].SetSpriteNumber(1, 0);
		}

		// Editor
		else if (m_zustand == 8) {
			if (hit == &menue_button) {
				menue_button.SetSpriteNumber(1, 1);
			}
			else {
				menue_button.SetSpriteNumber(1, 0);
			}
		}

		// Option
		else if (m_zustand == 10) {
			if (hit == &o_accept)
				o_accept.SetSpriteNumber(0, 1);
			else
				o_accept.SetSpriteNumber(0, 0);
			if (hit == &o_cancel)
				o_cancel.SetSpriteNumber(1, 1);
			else
				o_cancel.SetSpriteNumber(1, 0);
			if (hit == &slider.slider)
				slider.slider.SetSpriteNumber(1, 0);
			else
				slider.slider.SetSpriteNumber(0, 0);
		}

		// Speichern
		else if (m_zustand == 14) {
			if (hit == &files[0])
				files[0].SetSpriteNumber(0, 1);
			else
				files[0].SetSpriteNumber(0, 0);
			if (hit == &files[1])
				files[1].SetSpriteNumber(1, 1);
			else
				files[1].SetSpriteNumber(1, 0);
			if (hit == &files[2])
				files[2].SetSpriteNumber(2, 1);
			else
				files[2].SetSpriteNumber(2, 0);
			if (hit == &sl_accept)
				sl_accept.SetSpriteNumber(0, 1);
			else
				sl_accept.SetSpriteNumber(0, 0);
			if (hit == &sl_cancel)
				sl_cancel.SetSpriteNumber(1, 1);
			else
				sl_cancel.SetSpriteNumber(1, 0);
		}

		// Laden
		else if (m_zustand == 18) {
			if (hit == &files[0])
				files[0].SetSpriteNumber(0, 1);
			else
				files[0].SetSpriteNumber(0, 0);
			if (hit == &files[1])
				files[1].SetSpriteNumber(1, 1);
			else
				files[1].SetSpriteNumber(1, 0);
			if (hit == &files[2])
				files[2].SetSpriteNumber(2, 1);
			else
				files[2].SetSpriteNumber(2, 0);
			if (hit == &sl_accept)
				sl_accept.SetSpriteNumber(0, 1);
			else
				sl_accept.SetSpriteNumber(0, 0);
			if (hit == &sl_cancel)
				sl_cancel.SetSpriteNumber(1, 1);
			else
				sl_cancel.SetSpriteNumber(1, 0);
		}
		
		
		
		
	}
	list.Update(&dc, 0, 0);
	// redraw dirty region  

	CDialogEx::OnMouseMove(nFlags, point);
}

void CGoLDlg::AnimEngine(int ereignis) {
	float alpha = 0;
	int i = 0;
	CClientDC dc(this);

	/*CString string;
	string.Format(L"Zustand: %d, Ereignis: %d, Aktion: %d", m_zustand, ereignis, m_tabelle[ereignis][m_zustand].aktion);
	dc.TextOut(0,0,string);*/

	switch (m_tabelle[ereignis][m_zustand].aktion) {
	case -1: return; // ignore event
	case 0: break; // do nothing (but change m_zustand)
	case 1: 
		// Menü einblenden
		alpha = (menue.GetAlpha() + 0.1f);
		menue.SetAlpha(alpha);
		for (i = 0; i < 7; i++) button[i].SetAlpha(alpha);
		if (alpha >= 1.0f) {
			AnimEngine(12);
			return;
		}
		break;
	case 2: 
		// Menü ausblenden
		alpha = (menue.GetAlpha() - 0.1f);
		menue.SetAlpha(alpha);
		for (i = 0; i < 7; i++) button[i].SetAlpha(alpha);
		if (alpha <= 0.0f) {
			AnimEngine(13);
			return;
		}
		break;
	case 3: 
		// Menü rausporten
		menue.SetPosition(469, 1000);
		button[0].SetPosition(559, 1000);
		button[1].SetPosition(559, 1000);
		button[2].SetPosition(559, 1000);
		button[3].SetPosition(559, 1000);
		button[4].SetPosition(559, 1000);
		button[5].SetPosition(559, 1000);
		button[6].SetPosition(708, 1000);
		//Editor aktivieren
		menue_button.SetSpriteNumber(1, 0);
		for (int i = 0; i < 126; i++) {
			baneling[i].SetSpriteNumber(feld.field[(i % 14)][(i / 14)].animation = feld.field[(i % 14)][(i / 14)].life, 0);
		}
		break;
	case 4: 
		// Editor deaktivieren
		menue_button.SetSpriteNumber(0, 1);
		break;
	case 5:
		// Optionen einblenden
		alpha = (option.GetAlpha() + 0.1f);
		option.SetAlpha(alpha);
		o_accept.SetAlpha(alpha);
		o_cancel.SetAlpha(alpha);
		checkbox[0].SetAlpha(alpha);
		checkbox[1].SetAlpha(alpha);
		checkboxtext[0].SetAlpha(alpha);
		checkboxtext[1].SetAlpha(alpha);
		slider.SetAlpha(alpha);
		if (alpha >= 1.0f) {
			AnimEngine(14);
			return;
		}
		break;
	case 6: 
		// Optionen ausblenden
		alpha = (option.GetAlpha() - 0.1f);
		option.SetAlpha(alpha);
		o_accept.SetAlpha(alpha);
		o_cancel.SetAlpha(alpha);
		checkbox[0].SetAlpha(alpha);
		checkbox[1].SetAlpha(alpha);
		checkboxtext[0].SetAlpha(alpha);
		checkboxtext[1].SetAlpha(alpha);
		slider.SetAlpha(alpha);
		if (alpha <= 0.0f) {
			AnimEngine(15);
			return;
		}
		break;
	case 7: 
		// Speichern einblenden
		alpha = (saveload.GetAlpha() + 0.1f);
		saveload.SetAlpha(alpha);
		sl_accept.SetAlpha(alpha);
		sl_cancel.SetAlpha(alpha);
		for (i = 0; i < 3; i++) files[i].SetAlpha(alpha);
		if (alpha >= 1.0f) {
			AnimEngine(18);
			return;
		}
		break;
	case 8: 
		// Speichern ausblenden
		alpha = (saveload.GetAlpha() - 0.1f);
		saveload.SetAlpha(alpha);
		sl_accept.SetAlpha(alpha);
		sl_cancel.SetAlpha(alpha);
		for (i = 0; i < 3; i++) files[i].SetAlpha(alpha);
		if (alpha <= 0.0f) {
			AnimEngine(19);
			return;
		}
		break;
	case 9:
		// Laden einblenden
		alpha = (saveload.GetAlpha() + 0.1f);
		saveload.SetAlpha(alpha);
		sl_accept.SetAlpha(alpha);
		sl_cancel.SetAlpha(alpha);
		for (i = 0; i < 3; i++) files[i].SetAlpha(alpha);
		if (alpha >= 1.0f) {
			AnimEngine(20);
			return;
		}
		break;
	case 10:
		// Laden ausblenden
		alpha = (saveload.GetAlpha() - 0.1f);
		saveload.SetAlpha(alpha);
		sl_accept.SetAlpha(alpha);
		sl_cancel.SetAlpha(alpha);
		for (i = 0; i < 3; i++) files[i].SetAlpha(alpha);
		if (alpha <= 0.0f) {
			AnimEngine(21);
			return;
		}
		break;
	case 11:
		// Info einblenden
		alpha = (info.GetAlpha() + 0.1f);
		info.SetAlpha(alpha);
		i_accept.SetAlpha(alpha);
		i_cancel.SetAlpha(alpha);
		if (alpha >= 1.0f) {
			AnimEngine(16);
			return;
		}
		break;
	case 12:
		// Info ausblenden
		alpha = (info.GetAlpha() - 0.1f);
		info.SetAlpha(alpha);
		i_accept.SetAlpha(alpha);
		i_cancel.SetAlpha(alpha);
		if (alpha <= 0.0f) {
			AnimEngine(17);
			return;
		}
		break;
	case 13:
		// Speichern
		// feld.zustand_speichern(file);
		break;
	case 14:
		// Laden
		// feld.zustand_einlesen(file);
		break;
	case 15:
		//Menü reinporten
		menue.SetPosition(469, 219);
		button[0].SetPosition(559, 303);
		button[1].SetPosition(559, 355);
		button[1].SetSpriteNumber(0, 1);
		button[2].SetPosition(559, 460);
		button[2].SetSpriteNumber(0, 3);
		button[3].SetPosition(559, 512);
		button[3].SetSpriteNumber(0, 5);
		button[4].SetPosition(559, 610);
		button[4].SetSpriteNumber(0, 4);
		button[5].SetPosition(559, 407);
		button[5].SetSpriteNumber(0, 0);
		button[6].SetPosition(708, 407);
		button[6].SetSpriteNumber(1, 0);
		break;
	case 16:
		//Menü rausporten
		menue.SetPosition(469, 1000);
		button[0].SetPosition(559, 1000);
		button[1].SetPosition(559, 1000);
		button[2].SetPosition(559, 1000);
		button[3].SetPosition(559, 1000);
		button[4].SetPosition(559, 1000);
		button[5].SetPosition(559, 1000);
		button[6].SetPosition(708, 1000);
		break;
	case 17:
		//Info reinporten
		info.SetPosition(417, 361);
		i_accept.SetPosition(464, 555);
		i_accept.SetSpriteNumber(0, 0);
		i_cancel.SetPosition(819, 555);
		i_cancel.SetSpriteNumber(1, 0);
		break;
	case 18:
		//Info rausporten
		info.SetPosition(417, 1000);
		i_accept.SetPosition(464, 1000);
		i_cancel.SetPosition(819, 1000);
		break;
	case 19:
		//Menü rausporten
		menue.SetPosition(469, 1000);
		button[0].SetPosition(559, 1000);
		button[1].SetPosition(559, 1000);
		button[2].SetPosition(559, 1000);
		button[3].SetPosition(559, 1000);
		button[4].SetPosition(559, 1000);
		button[5].SetPosition(559, 1000);
		button[6].SetPosition(708, 1000);
		//Option reinporten
		option.SetPosition(417, 361);
		o_accept.SetPosition(464, 555);
		o_accept.SetSpriteNumber(0, 0);
		o_cancel.SetPosition(819, 555);
		o_cancel.SetSpriteNumber(1, 0);
		checkbox[0].SetPosition(498, 421);
		checkbox[1].SetPosition(498, 461);
		checkboxtext[0].SetPosition(538, 423);
		checkboxtext[1].SetPosition(538, 463);
		slider.SetPosition(497, 501);
		break;
	case 20:
		//Option rausporten
		option.SetPosition(417, 1000);
		o_accept.SetPosition(464, 1000);
		o_cancel.SetPosition(819, 1000);
		checkbox[0].SetPosition(498, 1000);
		checkbox[1].SetPosition(498, 1000);
		checkboxtext[0].SetPosition(538, 1000);
		checkboxtext[1].SetPosition(538, 1000);
		slider.SetPosition(497, 1000);
		//Menü reinporten
		menue.SetPosition(469, 219);
		button[0].SetPosition(559, 303);
		button[1].SetPosition(559, 355);
		button[1].SetSpriteNumber(0, 1);
		button[2].SetPosition(559, 460);
		button[2].SetSpriteNumber(0, 3);
		button[3].SetPosition(559, 512);
		button[3].SetSpriteNumber(0, 5);
		button[4].SetPosition(559, 610);
		button[4].SetSpriteNumber(0, 4);
		button[5].SetPosition(559, 407);
		button[5].SetSpriteNumber(0, 0);
		button[6].SetPosition(708, 407);
		button[6].SetSpriteNumber(1, 0);
		break;
	case 21:
		//Menü rausporten
		menue.SetPosition(469, 1000);
		button[0].SetPosition(559, 1000);
		button[1].SetPosition(559, 1000);
		button[2].SetPosition(559, 1000);
		button[3].SetPosition(559, 1000);
		button[4].SetPosition(559, 1000);
		button[5].SetPosition(559, 1000);
		button[6].SetPosition(708, 1000);
		//Saveload reinporten
		saveload.SetPosition(417, 361);
		sl_accept.SetPosition(464, 555);
		sl_accept.SetSpriteNumber(0, 0);
		sl_cancel.SetPosition(819, 555);
		sl_cancel.SetSpriteNumber(1, 0);
		files[0].SetPosition(467, 430);
		files[1].SetPosition(631, 430);
		files[2].SetPosition(795, 430);
		break;
	case 22:
		//Saveload rausporten
		saveload.SetPosition(417, 1000);
		sl_accept.SetPosition(464, 1000);
		sl_cancel.SetPosition(819, 1000);
		files[0].SetPosition(467, 1000);
		files[1].SetPosition(631, 1000);
		files[2].SetPosition(795, 1000);
		break;
	case 23:
		//KillTimer
		/*KillTimer(2);
		anim = false;
		button[0].SetSpriteNumber(0, 0);*/
		break;
	}

	m_zustand = m_tabelle[ereignis][m_zustand].naechster_zustand;
	list.Update(&dc, 0, 0);
}

void CGoLDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	CSprite* hit = list.HitTest(point);
	CClientDC dc(this);
	int x, y;

	//Standard
	if (m_zustand == 0) {
		if ((hit == &info_button) && (clicked == &info_button)) {
			AnimEngine(7);
		}
		else if ((hit == &menue_button) && (clicked == &menue_button)) {
			AnimEngine(1);
		}
	}

	// Info
	else if (m_zustand == 2) {
		if ((hit == &i_accept) && (clicked == &i_accept)) {
			AnimEngine(8);
		}
		else if ((hit == &i_cancel) && (clicked == &i_cancel)) {
			AnimEngine(8);
		}
		else if ((hit == &info_button) && (clicked == &info_button)) {
			AnimEngine(8);
		}
	}

	// Menü
	else if (m_zustand == 5) {
		if ((hit == &button[0]) && (clicked == &button[0])) {
			if (anim) {
				anim = false;
				KillTimer(2);
				button[0].SetSpriteNumber(1, 0);
			}
			else {
				anim = true;
				SetTimer(2, slider.GetTime(), NULL);
				button[0].SetSpriteNumber(1, 2);
			}
		}
		else if ((hit == &button[1]) && (clicked == &button[1])) {
			feld.feld_fuellen_random(30);
			for (int i = 0; i < 126; i++) {
				baneling[i].SetSpriteNumber(feld.field[(i % 14)][(i / 14)].animation = feld.field[(i % 14)][(i / 14)].life, 0);
			}
		}
		else if ((hit == &button[2]) && (clicked == &button[2])) {
			anim = false;
			KillTimer(2);
			button[0].SetSpriteNumber(0, 0);
			AnimEngine(2);
		}
		else if ((hit == &button[3]) && (clicked == &button[3])) {
			AnimEngine(3);
		}
		else if ((hit == &button[4]) && (clicked == &button[4])) {
			AnimEngine(4);
		}
		else if ((hit == &menue_button) && (clicked == &menue_button)) {
			AnimEngine(4);
		}
		else if ((hit == &button[5]) && (clicked == &button[5])) {
			AnimEngine(9);
		}
		else if ((hit == &button[6]) && (clicked == &button[6])) {
			AnimEngine(10);
		}
	}

	// Editor
	else if (m_zustand == 8) {
		for (int i = 0; i < 126; i++) {
			if ((hit == &baneling[i]) && (clicked == &baneling[i])) {
				x = (i % 14);
				y = (i / 14);
				baneling[i].SetSpriteNumber(feld.field[x][y].animation = feld.field[x][y].life = !feld.field[x][y].life, 0);
			}
		}
		if ((hit == &menue_button) && (clicked == &menue_button)) {
			AnimEngine(5);
		}
	}

	// Option
	else if (m_zustand == 10) {
		if ((hit == &checkbox[0]) && (clicked == &checkbox[0])) {
			logodrag = !logodrag;
			if (logodrag) checkbox[0].SetSpriteNumber(0, 1);
			else checkbox[0].SetSpriteNumber(0, 0);
		}
		else if ((hit == &checkbox[1]) && (clicked == &checkbox[1])) {
			logoanim = !logoanim;
			if (logoanim) checkbox[1].SetSpriteNumber(0, 1);
			else checkbox[1].SetSpriteNumber(0, 0);
		}
		else if ((hit == &o_accept) && (clicked == &o_accept)) {
			AnimEngine(6);
		}
		else if ((hit == &o_cancel) && (clicked == &o_cancel)) {
			AnimEngine(6);
		}
		else if ((hit == &menue_button) && (clicked == &menue_button)) {
			AnimEngine(6);
		}
	}

	// Speichern
	else if (m_zustand == 14) {
		if ((hit == &files[0]) && (clicked == &files[0])) {
			feld.zustand_speichern("file_a.save");
		}
		else if ((hit == &files[1]) && (clicked == &files[1])) {
			feld.zustand_speichern("file_b.save");
		}
		else if ((hit == &files[2]) && (clicked == &files[2])) {
			feld.zustand_speichern("file_c.save");
		}
		AnimEngine(11);
	}

	// Laden
	else if (m_zustand == 18) {
		if ((hit == &files[0]) && (clicked == &files[0])) {
			feld.zustand_einlesen("file_a.save");
			for (int i = 0; i < 126; i++) {
				baneling[i].SetSpriteNumber(feld.field[(i % 14)][(i / 14)].animation = feld.field[(i % 14)][(i / 14)].life, 0);
			}
			AnimEngine(11);
		}
		else if ((hit == &files[1]) && (clicked == &files[1])) {
			feld.zustand_einlesen("file_b.save");
			for (int i = 0; i < 126; i++) {
				baneling[i].SetSpriteNumber(feld.field[(i % 14)][(i / 14)].animation = feld.field[(i % 14)][(i / 14)].life, 0);
			}
			AnimEngine(11);
		}
		else if ((hit == &files[2]) && (clicked == &files[2])) {
			feld.zustand_einlesen("file_c.save");
			for (int i = 0; i < 126; i++) {
				baneling[i].SetSpriteNumber(feld.field[(i % 14)][(i / 14)].animation = feld.field[(i % 14)][(i / 14)].life, 0);
			}
			AnimEngine(11);
		}
		else if ((hit == &sl_accept) && (clicked == &sl_accept)) {
			AnimEngine(11);
		}
		else if ((hit == &sl_cancel) && (clicked == &sl_cancel)) {
			AnimEngine(11);
		}
	}

	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein, und/oder benutzen Sie den Standard.
	list.Update(&dc, 0, 0);
	CDialogEx::OnLButtonUp(nFlags, point);
}

void CGoLDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CSprite* hit = list.HitTest(point);
	if (hit == &slider.slider) {
		captured = hit;
	}
	else if (hit == &logo) {
		captured = hit;
		mousePos = point;
	}
	else {
		clicked = hit;
	}
	
	CDialogEx::OnLButtonDown(nFlags, point);
}
