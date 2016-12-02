
// GoLDlg.h: Headerdatei
//
#include "spritelib.h"
#include "Field.h"
#include "Slider.h"
#pragma once


// CGoLDlg-Dialogfeld
class CGoLDlg : public CDialogEx
{
// Konstruktion
public:
	CGoLDlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_GOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung

	// Implementierung
protected:
	HICON m_hIcon;
	//Hintergrund
	CSprite hintergrund;
	CSprite black;
	CSprite logo;
	//Spielfeld
	CSprite baneling[14*9];
	//Menü
	CSprite button[7];
	CSprite menue;
	CSprite menue_button;
	//Option
	CSprite option;
	CSprite o_accept;
	CSprite o_cancel;
	CSprite checkbox[2];
	CSprite checkboxtext[2];
	CSlider slider;
	bool logoanim;
	bool logodrag;
	//Info
	CSprite info_button;
	CSprite info;
	CSprite i_accept;
	CSprite i_cancel;
	//Save and Load
	CSprite files[3];
	CSprite saveload;
	CSprite sl_accept;
	CSprite sl_cancel;
	//Drag&Drop
	CSprite* captured;
	CSprite* clicked;
	CPoint mousePos;
	CDIB buffer;
	CSpriteList list;
	CField feld;
	//Zustände
	bool anim;
	bool edit;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void AnimEngine(int ereignis);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
