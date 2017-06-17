/*
 * PROJECT:     ReactOS shell extensions
 * LICENSE:     GPL - See COPYING in the top level directory
 * FILE:        dll/shellext/qcklnch/CISFBand.h
 * PURPOSE:     Quick Launch Toolbar (Taskbar Shell Extension)
 * PROGRAMMERS: Shriraj Sawant a.k.a SR13 <sr.official@hotmail.com>
 */
#pragma once

//COM class for cisfband
class CISFBand :
    public CComCoClass<CISFBand>,
    public CComObjectRootEx<CComMultiThreadModelNoCS>,
    public IObjectWithSite,
    public IDeskBand,
    public IDeskBar,
    public IPersistStream,
    public IWinEventHandler,
    public IOleCommandTarget
{
    CComPtr<IUnknown> m_Site; 
    CComPtr<IUnknown> m_punkISFB;

    HINSTANCE m_hInstance; 
    HWND m_hWnd;
    HWND m_hWndStartButton;
    DWORD m_BandID;    

public:

    CISFBand();
    virtual ~CISFBand();

//IObjectWithSite

    virtual HRESULT STDMETHODCALLTYPE GetSite(
      /*[in]*/  REFIID riid,
      /*[out]*/ void   **ppvSite
    );

    virtual HRESULT STDMETHODCALLTYPE SetSite(
      /*[in]*/ IUnknown *pUnkSite
    );
 
//IDeskBand

    virtual HRESULT STDMETHODCALLTYPE GetWindow(
        OUT HWND *phwnd
    );    

    virtual HRESULT STDMETHODCALLTYPE ContextSensitiveHelp(
        IN BOOL fEnterMode
    );    

    virtual HRESULT STDMETHODCALLTYPE ShowDW(
        IN BOOL bShow
    );    

    virtual HRESULT STDMETHODCALLTYPE CloseDW(
        IN DWORD dwReserved
    );    

    virtual HRESULT STDMETHODCALLTYPE ResizeBorderDW(
        LPCRECT prcBorder,
        IUnknown *punkToolbarSite,
        BOOL fReserved
    );    

    virtual HRESULT STDMETHODCALLTYPE GetBandInfo(
        IN DWORD dwBandID,
        IN DWORD dwViewMode,
        IN OUT DESKBANDINFO *pdbi
    );    

//IDeskBar

    virtual HRESULT STDMETHODCALLTYPE GetClient(
      /*[out]*/ IUnknown **ppunkClient
    );

    virtual HRESULT STDMETHODCALLTYPE OnPosRectChangeDB(
      /*[in]*/ LPRECT prc
    );

    virtual HRESULT STDMETHODCALLTYPE SetClient(
      /*[in, optional]*/ IUnknown *punkClient
    );

//IPersistStream

    virtual HRESULT STDMETHODCALLTYPE GetClassID(
      /*[out]*/ OUT CLSID *pClassID
    );

    virtual HRESULT STDMETHODCALLTYPE GetSizeMax(
      /*[out]*/ ULARGE_INTEGER *pcbSize
    );

    virtual HRESULT STDMETHODCALLTYPE IsDirty();

    virtual HRESULT STDMETHODCALLTYPE Load(
      /*[in]*/ IStream *pStm
    );

    virtual HRESULT STDMETHODCALLTYPE Save(
      /*[in]*/ IStream *pStm,
      /*[in]*/ BOOL    fClearDirty
    );

//IWinEventHandler

    virtual HRESULT STDMETHODCALLTYPE ProcessMessage(
        IN HWND hWnd,
        IN UINT uMsg,
        IN WPARAM wParam,
        IN LPARAM lParam,
        OUT LRESULT *plrResult
    );

    virtual HRESULT STDMETHODCALLTYPE ContainsWindow(
        IN HWND hWnd
    );

    virtual HRESULT STDMETHODCALLTYPE OnWinEvent(
        HWND hWnd, 
        UINT uMsg, 
        WPARAM wParam, 
        LPARAM lParam, 
        LRESULT *theResult
    );

    virtual HRESULT STDMETHODCALLTYPE IsWindowOwner(
        HWND hWnd
    );

//IOleCommandTarget

    virtual HRESULT STDMETHODCALLTYPE Exec(
      /*[in]*/      const GUID    *pguidCmdGroup,
      /*[in]*/            DWORD   nCmdID,
      /*[in]*/            DWORD   nCmdexecopt,
      /*[in]*/            VARIANT *pvaIn,
      /*[in, out]*/       VARIANT *pvaOut
    );

    virtual HRESULT STDMETHODCALLTYPE QueryStatus(
      /*[in]*/      const GUID       *pguidCmdGroup,
      /*[in]*/            ULONG      cCmds,
      /*[in, out]*/       OLECMD     prgCmds[],
      /*[in, out]*/       OLECMDTEXT *pCmdText
    );

//*****************************************************************************************************
    
    DECLARE_NOT_AGGREGATABLE(CISFBand)
    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CISFBand)
        COM_INTERFACE_ENTRY2_IID(IID_IOleWindow, IOleWindow, IDeskBand)
        COM_INTERFACE_ENTRY_IID(IID_IDeskBand, IDeskBand)
        COM_INTERFACE_ENTRY_IID(IID_IObjectWithSite, IObjectWithSite)
        COM_INTERFACE_ENTRY_IID(IID_IPersist, IPersist)
        COM_INTERFACE_ENTRY_IID(IID_IPersistStream, IPersistStream)
        COM_INTERFACE_ENTRY_IID(IID_IWinEventHandler, IWinEventHandler)
        COM_INTERFACE_ENTRY_IID(IID_IOleCommandTarget, IOleCommandTarget)
    END_COM_MAP()    
};