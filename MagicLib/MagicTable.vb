Imports System.Math
Imports System
Imports System.Windows.Forms
Imports System.IO.File
Imports System.IO.Path
Imports Microsoft.Office.Interop.Excel
Imports GcadVbaLib

<ComClass(MagicTable.ClassId, MagicTable.InterfaceId, MagicTable.EventsId)> _
Public Class MagicTable

#Region "COM GUID"
    ' 다음 GUID는 이 클래스의 COM ID와 COM 인터페이스를 
    ' 제공합니다. 이 GUID를 변경하면 기존 클라이언트가 해당 
    ' 클래스에 더 이상 액세스할 수 없게 됩니다.
    Public Const ClassId As String = "1a7fbe55-6cb1-425e-a316-b461d81bb6ad"
    Public Const InterfaceId As String = "cf021341-9964-4ee0-9d30-f9c25585f1be"
    Public Const EventsId As String = "ed8b1fa2-2ec5-460f-8599-90f083cee88a"
#End Region

    ' 생성 가능한 COM 클래스에는 매개 변수가 없는 Public Sub New()가 
    ' 포함되어 있어야 합니다. 그렇지 않으면 이 클래스가 
    ' COM 레지스트리에 등록되지 않으며 CreateObject를 
    ' 통해 이 클래스가 생성되지 않습니다.
    Public Sub New()
        MyBase.New()
    End Sub

    Private Const APPNAME As String = "MAGIC_TABLE"

    Const QS_KEY = &H1
    Const QS_MOUSEMOVE = &H2
    Const QS_MOUSEBUTTON = &H4
    Const QS_MOUSE = (QS_MOUSEMOVE Or QS_MOUSEBUTTON)
    Const QS_INPUT = (QS_MOUSE Or QS_KEY)
    Private Declare Function GetQueueStatus Lib "user32" (ByVal fuFlags As Long) As Long

    Const xlR1C1 As Long = -4150
    Const xlEdgeLeft As Long = 7
    Const xlEdgeTop As Long = 8
    Const xlEdgeBottom As Long = 9
    Const xlEdgeRight As Long = 10

    Const gcSelectionSetCrossing As Integer = 1
    Const gcSelectionSetAll As Integer = 5

    Const acAlignmentLeft As Integer = 0
    Const acAlignmentCenter As Integer = 1
    Const acAlignmentRight As Integer = 2
    Const acAlignmentAligned As Integer = 3
    Const acAlignmentMiddle As Integer = 4
    Const acAlignmentFit As Integer = 5
    Const acAlignmentTopLeft As Integer = 6
    Const acAlignmentTopCenter As Integer = 7
    Const acAlignmentTopRight As Integer = 8
    Const acAlignmentMiddleLeft As Integer = 9
    Const acAlignmentMiddleCenter As Integer = 10
    Const acAlignmentMiddleRight As Integer = 11
    Const acAlignmentBottomLeft As Integer = 12
    Const acAlignmentBottomCenter As Integer = 13
    Const acAlignmentBottomRight As Integer = 14

    Structure RangeInfo
        Dim CellW As Double
        Dim CellH As Double
        Dim RowHidden As Boolean
        Dim ColHidden As Boolean
        Dim Text As String
        Dim TextH As Double
        Dim CellFormat As String
        Dim TextHAdj As String
        Dim TextVAdj As String
        Dim TextOrient As Long
        Dim TextTab As Integer
        Dim Merge As Boolean
        Dim MergeArea As String
        Dim MergeText As String
        Dim xlEdgeL As Boolean
        Dim xlEdgeR As Boolean
        Dim xlEdgeT As Boolean
        Dim xlEdgeB As Boolean
        Dim CellRow As Long
        Dim CellCol As Long
    End Structure

    Structure MergeBoder
        Dim LL As Boolean
        Dim RL As Boolean
        Dim TL As Boolean
        Dim BL As Boolean
    End Structure

    Structure CadTable
        Dim LL As Integer
        Dim RL As Integer
        Dim TL As Integer
        Dim BL As Integer
        Dim LX As Double
        Dim LY As Double
        Dim RX As Double
        Dim RY As Double
    End Structure

    Structure MergeCell
        Dim SR As Double
        Dim SC As Double
        Dim ER As Double
        Dim EC As Double
        Dim Text As String
        Dim TextHAdj As Long
        Dim TextVAdj As Long
        Dim TextOrient As Long
        Dim Handle As String
    End Structure


    Dim sAll As String
    Dim vIns As Object
    Dim sExlName As String ' 엑셀 가져온 워크북,시트이름
    Dim vSSpnt As Object
    Dim vSEpnt As Object
    Dim tbl(,) As CadTable
    Dim vTmpCol() As Object    '초기 열
    Dim vTmpRow() As Object    '초기 행
    Dim dCol(3) As Double
    Dim dRow(3) As Double
    Dim vExplode As Object
    Dim iRow As Integer
    Dim iCol As Integer
    Dim vMerge() As MergeCell
    Dim col As Collection

    Dim tbl_Title As String
    Dim tbl_ChkTable As Boolean
    Dim tbl_ChkText As Boolean
    Dim tbl_OptAutoW As Boolean
    Dim tbl_OptIntW As Boolean
    Dim tbl_OptUserW As Boolean
    Dim tbl_OptAutoH As Boolean
    Dim tbl_OptIntH As Boolean
    Dim tbl_OptUserH As Boolean
    Dim tbl_DTwAng As Double
    Dim tbl_TextWid As Double
    Dim tbl_TextHig As Double
    Dim tbl_ExcelHig As Double
    Dim tbl_ChkFit As Boolean
    Dim tbl_ChkSpace As Boolean
    Dim tbl_ChkXdata As Boolean
    Dim tbl_ChkSelect As Boolean
    Dim tbl_ChkExpand As Boolean
    Dim tbl_ChkBound As Boolean
    Dim tbl_ChkNoMerge As Boolean
    Dim tbl_TableWid As Double
    Dim tbl_TableHig As Double
    Dim tbl_LineLayer As String
    Dim tbl_LineColor As String
    Dim tbl_TextLayer As String
    Dim tbl_TextColor As String
    Dim tbl_TextStyle As String
    Dim tbl_HorArrange As Integer
    Dim tbl_VerArrange As Integer

    Public Property Title() As String
        Get
            Title = tbl_Title
        End Get
        Set(value As String)
            tbl_Title = value
        End Set
    End Property

    Public Property CheckTable() As Boolean
        Get
            CheckTable = tbl_ChkTable
        End Get
        Set(value As Boolean)
            tbl_ChkTable = value
        End Set
    End Property

    Public Property CheckText() As Boolean
        Get
            CheckText = tbl_ChkText
        End Get
        Set(value As Boolean)
            tbl_ChkText = value
        End Set
    End Property

    Public Property AutoWidth() As Boolean
        Get
            AutoWidth = tbl_OptAutoW
        End Get
        Set(value As Boolean)
            tbl_OptAutoW = value
        End Set
    End Property

    Public Property IntWidth() As Boolean
        Get
            IntWidth = tbl_OptIntW
        End Get
        Set(value As Boolean)
            tbl_OptIntW = value
        End Set
    End Property

    Public Property UserWidth() As Boolean
        Get
            UserWidth = tbl_OptUserW
        End Get
        Set(value As Boolean)
            tbl_OptUserW = value
        End Set
    End Property

    Public Property AutoHeight() As Boolean
        Get
            AutoHeight = tbl_OptAutoH
        End Get
        Set(value As Boolean)
            tbl_OptAutoH = value
        End Set
    End Property

    Public Property IntHeight() As Boolean
        Get
            IntHeight = tbl_OptIntH
        End Get
        Set(value As Boolean)
            tbl_OptIntH = value
        End Set
    End Property

    Public Property UserHeight() As Boolean
        Get
            UserHeight = tbl_OptUserH
        End Get
        Set(value As Boolean)
            tbl_OptUserH = value
        End Set
    End Property

    Public Property TwistAngle() As Double
        Get
            TwistAngle = tbl_DTwAng
        End Get
        Set(value As Double)
            tbl_DTwAng = value
        End Set
    End Property

    Public Property TextWidth() As Double
        Get
            TextWidth = tbl_TextWid
        End Get
        Set(value As Double)
            tbl_TextWid = value
        End Set
    End Property

    Public Property TextHeight() As Double
        Get
            TextHeight = tbl_TextHig
        End Get
        Set(value As Double)
            tbl_TextHig = value
        End Set
    End Property

    Public Property ExcelHeight() As Double
        Get
            ExcelHeight = tbl_ExcelHig
        End Get
        Set(value As Double)
            tbl_ExcelHig = value
        End Set
    End Property

    Public Property CheckFit() As Boolean
        Get
            CheckFit = tbl_ChkFit
        End Get
        Set(value As Boolean)
            tbl_ChkFit = value
        End Set
    End Property

    Public Property CheckSpace() As Boolean
        Get
            CheckSpace = tbl_ChkSpace
        End Get
        Set(value As Boolean)
            tbl_ChkSpace = value
        End Set
    End Property

    Public Property CheckXdata() As Boolean
        Get
            CheckXdata = tbl_ChkXdata
        End Get
        Set(value As Boolean)
            tbl_ChkXdata = value
        End Set
    End Property

    Public Property CheckSelect() As Boolean
        Get
            CheckSelect = tbl_ChkSelect
        End Get
        Set(value As Boolean)
            tbl_ChkSelect = value
        End Set
    End Property

    Public Property CheckExpand() As Boolean
        Get
            CheckExpand = tbl_ChkExpand
        End Get
        Set(value As Boolean)
            tbl_ChkExpand = value
        End Set
    End Property

    Public Property CheckBound() As Boolean
        Get
            CheckBound = tbl_ChkBound
        End Get
        Set(value As Boolean)
            tbl_ChkBound = value
        End Set
    End Property

    Public Property CheckNoMerge() As Boolean
        Get
            CheckNoMerge = tbl_ChkNoMerge
        End Get
        Set(value As Boolean)
            tbl_ChkNoMerge = value
        End Set
    End Property

    Public Property TableWidth() As Double
        Get
            TableWidth = tbl_TableWid
        End Get
        Set(value As Double)
            tbl_TableWid = value
        End Set
    End Property

    Public Property TableHeight() As Double
        Get
            TableHeight = tbl_TableHig
        End Get
        Set(value As Double)
            tbl_TableHig = value
        End Set
    End Property

    Public Property LineLayer() As String
        Get
            LineLayer = tbl_LineLayer
        End Get
        Set(value As String)
            tbl_LineLayer = value
        End Set
    End Property

    Public Property LineColor() As String
        Get
            LineColor = tbl_LineColor
        End Get
        Set(value As String)
            tbl_LineColor = value
        End Set
    End Property

    Public Property TextLayer() As String
        Get
            TextLayer = tbl_TextLayer
        End Get
        Set(value As String)
            tbl_TextLayer = value
        End Set
    End Property

    Public Property TextColor() As String
        Get
            TextColor = tbl_TextColor
        End Get
        Set(value As String)
            tbl_TextColor = value
        End Set
    End Property

    Public Property TextStyle() As String
        Get
            TextStyle = tbl_TextStyle
        End Get
        Set(value As String)
            tbl_TextStyle = value
        End Set
    End Property

    Public Property HorArrange() As Integer
        Get
            HorArrange = tbl_HorArrange
        End Get
        Set(value As Integer)
            tbl_HorArrange = value
        End Set
    End Property

    Public Property VerArrange() As Integer
        Get
            VerArrange = tbl_VerArrange
        End Get
        Set(value As Integer)
            tbl_VerArrange = value
        End Set
    End Property


    Public Sub UpdateText(ByVal bToExcel As Boolean, Optional ByVal bSelect As Boolean = False)
        Dim oExcel As Object
        Dim oSheet As Object

        On Error Resume Next
        oExcel = GetObject(, "Excel.Application")
        If oExcel Is Nothing Then
            Err.Clear()
            If bToExcel Then
                MsgBox("Excel을 실행하고 데이터를 업데이트할 시트를 활성해 주십시오", vbInformation, tbl_Title)
            Else
                MsgBox("Excel을 실행하고 데이터를 가져올 시트를 활성해 주십시오", vbInformation, tbl_Title)
            End If
            GoTo ErrorHandler
        End If

        oSheet = oExcel.ActiveSheet
        If Err.Number <> 0 Then
            Err.Clear()
            MsgBox("Excel에 열린 문서가 없습니다", vbInformation, tbl_Title)
            GoTo ErrorHandler
        End If

        If oSheet.ProtectContents Then
            MsgBox("시트가 보호되어 있거나" & vbCr & _
                   "Excel에 열린 문서가 없습니다", vbInformation, tbl_Title)
            GoTo ErrorHandler
        End If

        InitLibrary()

        On Error GoTo ErrorHandler

        Dim oSel As GcadSelectionSet
        Dim iXType(0) As Integer
        Dim vXData(0) As Object

        iXType(0) = 1001
        vXData(0) = APPNAME

        oSel = CreateSelSet("MagicSS")

        If bSelect Then
            '일부만 선택
            oSel.SelectOnScreen(iXType, vXData)
        Else
            '전체 선택
            oSel.Select(gcSelectionSetAll, , , iXType, vXData)
        End If

        If oSel.Count = 0 Then
            If bToExcel Then
                MsgBox("엑셀 시트의 내용을 업데이트할 문자가 현재 도면에 없습니다", , tbl_Title)
            Else
                MsgBox("엑셀 시트의 내용을 적용할 문자가 현재 도면에 없습니다", , tbl_Title)
            End If
            GoTo ErrorHandler
        End If

        Dim vType As Object = Nothing
        Dim vData As Object = Nothing
        Dim i As Long
        Dim iCnt As Long '같은 시트에 기록된 수
        Dim sBook As String
        Dim sSheet As String
        Dim sTmpB As String
        Dim sTmpS As String = ""
        Dim sText As String

        sBook = oExcel.ActiveWorkbook.name
        sBook.Replace(".xls", "")
        sSheet = oSheet.name

        For i = 0 To oSel.Count - 1
            With oSel.Item(i)
                .GetXData(APPNAME, vType, vData)
                If Not IsNothing(vType) Then
                    '엑셀시트이름 기록
                    If InStr(sTmpS, vData(1)) = 0 Then
                        sTmpS = sTmpS & ", " & vData(1)
                    End If
                    '워크북 이름과 엑셀시트이름이 맞으면
                    If vData(1) = sBook & "|" & sSheet Then
                        If bToExcel Then
                            If .ObjectName = "AcDbMText" Then
                                sText = UnformatMtext(.TextString)
                            Else
                                sText = .TextString
                                sText.Replace("%%%", "%")
                            End If
                            oSheet.Cells(vData(2), vData(3)) = sText
                        Else
                            .TextString = oSheet.Cells(vData(2), vData(3)).Text
                        End If
                        iCnt = iCnt + 1
                    End If
                End If
            End With
        Next

        Dim iPos As Integer
        If iCnt = 0 Then
            If Left$(sTmpS, 1) = "," Then sTmpS = Right$(sTmpS, Len(sTmpS) - 2)
            iPos = InStr(sTmpS, "|")
            sTmpB = Mid$(sTmpS, 1, iPos - 1)
            sTmpS = Mid$(sTmpS, iPos + 1, Len(sTmpS))
            If bToExcel Then
                MsgBox("활성된 엑셀시트로 업데이트할 문자가 아닙니다" & vbCrLf & vbCrLf & _
                       "현재 도면에 문자들은 [" & sTmpB & " 파일의 " & sTmpS & " 시트]와 연결되어 있습니다  " & vbCrLf & _
                       "적합한 엑셀 시트를 활성화 해주십시오", , tbl_Title)
            Else
                MsgBox("활성된 엑셀시트 값을 적용할 문자가 없습니다" & vbCrLf & vbCrLf & _
                       "현재 도면에 문자들은 [" & sTmpB & " 파일의 " & sTmpS & " 시트]와 연결되어 있습니다  " & vbCrLf & _
                       "적합한 엑셀 시트를 활성화 해주십시오", , tbl_Title)
            End If
        Else
            If bToExcel Then
                MsgBox("도면 → 엑셀 업데이트 완료", , tbl_Title)
            Else
                MsgBox("엑셀 → 도면 업데이트 완료", , tbl_Title)
            End If
        End If

ErrorHandler:
        UninitLibrary()
        oExcel = Nothing
        oSheet = Nothing
    End Sub

    Private Sub ClearXData(oEnt As GcadObject, Optional sRegApp As String = "")
        Dim vType As Object = Nothing
        Dim vData As Object = Nothing
        Dim iNewType(0) As Integer
        Dim vNewData(0) As Object
        Dim i As Integer

        oEnt.GetXData(sRegApp, vType, vData)
        If Not IsNothing(vType) Then
            For i = LBound(vType) To UBound(vType)
                If vType(i) = 1001 Then
                    '캐드 자체 XDATA는 삭제하면안됨
                    If Not vData(i) Like "GCAD" Then
                        iNewType(0) = 1001
                        vNewData(0) = vData(i)
                        oEnt.SetXData(iNewType, vNewData)
                    End If
                End If
            Next i
        End If
    End Sub

    Public Sub ClearText()
        Dim oSel As GcadSelectionSet
        Dim iXType(0) As Integer
        Dim vXData(0) As Object
        Dim oEnt As GcadEntity


        InitLibrary()

        On Error Resume Next

        oSel = CreateSelSet("MagicSS")

        iXType(0) = 1001
        vXData(0) = APPNAME
        oSel.Select(gcSelectionSetAll, , , iXType, vXData)

        If oSel.Count = 0 Then GoTo ErrorHandler

        For Each oEnt In oSel
            Call ClearXData(oEnt, APPNAME)
        Next

ErrorHandler:
        ' MsgBox "이 기능과 관련되어 문자에 추가된 확장데이터가 모두 삭제되었습니다  ", , tbl_Title
        UninitLibrary()
        oSel = Nothing
    End Sub


    Private Function UnformatMtext(ByVal sString As String) As String
        Dim iPos1 As Integer
        Dim iPos2 As Integer
        Dim iPos3 As Integer
        Dim iStart As Integer
        Dim sCom As String
        Dim sReplace As String = ""
        Dim sLittle As String

        Select Case Left$(sString, 4)
            Case "\A0;", "\A1;", "\A2;"
                sString = Mid$(sString, iPos1 + 5)
        End Select

        iStart = 1
        Do
            iPos1 = InStr(sString, "%%")
            If iPos1 = 0 Then
                Exit Do
            Else
                Select Case Mid$(sString, iPos1 + 2, 1)
                    Case "P"
                        sString.Replace("%%P", "+or-")
                    Case "D"
                        sString.Replace("%%D", " deg")
                    Case Else
                        Exit Do
                End Select
            End If
        Loop

        Do
            iPos1 = InStr(iStart, sString, "\", vbTextCompare)
            If iPos1 = 0 Then Exit Do
            sCom = Mid$(sString, iPos1, 2)
            Select Case sCom
                Case "\p"
                    iPos2 = InStr(1, sString, ";")
                    sString = Mid$(sString, iPos2 + 1)
                Case "\A", "\C", "\f", "\F", "\H", "\Q", "\T", "\W"
                    iPos2 = InStr(iPos1 + 2, sString, ";", vbTextCompare)
                    iPos3 = InStr(iPos1 + 2, sString, sCom, vbTextCompare)
                    If iPos3 = 0 Then
                        sString = Left$(sString, iPos1 - 1) & Mid$(sString, iPos2 + 1)
                    End If
                    Do While iPos3 > 0
                        iPos2 = InStr(iPos3, sString, ";", vbTextCompare)
                        sString = Left$(sString, iPos3 - 1) & Mid$(sString, iPos2 + 1)
                        iPos3 = InStr(1, sString, sCom, vbTextCompare)
                    Loop
                Case "\L", "\O"
                    sLittle = LCase(sCom)
                    iPos2 = InStr(iPos1 + 2, sString, sLittle, vbTextCompare)
                    If iPos2 = 0 Then
                        sString = Left$(sString, iPos1 - 1) & Mid$(sString, iPos1 + 2)
                    Else
                        sString = Left$(sString, iPos1 - 1) & Mid$(sString, iPos1 + 2, iPos2 - (iPos1 + 2)) & Mid$(sString, iPos2 + 2)
                    End If
                Case "\S"
                    iPos2 = InStr(iPos1 + 2, sString, ";", vbTextCompare)
                    iPos3 = InStr(iPos1 + 2, sString, "/", vbTextCompare)
                    If iPos3 = 0 Or iPos3 > iPos2 Then
                        iPos3 = InStr(iPos1 + 2, sString, "#", vbTextCompare)
                    End If
                    If iPos3 = 0 Or iPos3 > iPos2 Then
                        iPos3 = InStr(iPos1 + 2, sString, "^", vbTextCompare)
                    End If
                    sString = Left$(sString, iPos1 - 1) & Mid$(sString, iPos1 + 2, iPos3 - (iPos1 + 2)) _
                            & "/" & Mid$(sString, iPos3 + 1, (iPos2) - (iPos3 + 1)) & Mid$(sString, iPos2 + 1)

                Case "\U"
                    sLittle = Mid$(sString, iPos1 + 3, 4)
                    Debug.Print(sLittle)
                    Select Case sLittle
                        Case "2248"
                            sReplace = "ALMOST EQUAL"
                        Case "2220"
                            sReplace = "ANGLE"
                        Case "2104"
                            sReplace = "CENTER LINE"
                        Case "0394"
                            sReplace = "DELTA"
                        Case "0278"
                            sReplace = "ELECTRIC PHASE"
                        Case "E101"
                            sReplace = "FLOW LINE"
                        Case "2261"
                            sReplace = "IDENTITY"
                        Case "E200"
                            sReplace = "INITIAL LENGTH"
                        Case "E102"
                            sReplace = "MONUMENT LINE"
                        Case "2260"
                            sReplace = "NOT EQUAL"
                        Case "2126"
                            sReplace = "OHM"
                        Case "03A9"
                            sReplace = "OMEGA"
                        Case "214A"
                            sReplace = "PROPERTY LINE"
                        Case "2082"
                            sReplace = "SUBSCRIPT2"
                        Case "00B2"
                            sReplace = "SQUARED"
                        Case "00B3"
                            sReplace = "CUBED"
                    End Select
                    sString.Replace("\U+" & sLittle, sReplace)

                Case "\~"
                    sString.Replace("\~", " ")

                Case "\\"
                    iStart = iPos1 + 2
                    sString.Replace("\\", "\")
                    GoTo Selectagain

                Case "\P"
                    iStart = iPos1 + 1
                    GoTo Selectagain
                Case Else
                    Exit Do
            End Select
Selectagain:
        Loop

        Do
            iPos1 = InStr(1, sString, "\P", vbTextCompare)
            If iPos1 = 0 Then
                Exit Do
            Else
                sString = Left$(sString, iPos1 - 1) & vbLf & Mid$(sString, iPos1 + 2)
            End If
        Loop

        For iStart = 0 To 1
            If iStart = 0 Then
                sCom = "}"
            Else
                sCom = "{"
            End If
            iPos2 = InStr(1, sString, sCom)

            Do While iPos2 > 0
                sString = Left$(sString, iPos2 - 1) & Mid$(sString, iPos2 + 1)
                iPos2 = InStr(1, sString, sCom)
            Loop
        Next iStart
        UnformatMtext = sString
    End Function

    Private Function DrawLine(dSpnt() As Double, dEpnt() As Double) As GcadLine
        DrawLine = WorkSpace.AddLine(dSpnt, dEpnt)
        With DrawLine
            .Layer = tbl_LineLayer
            If Not LCase(tbl_LineColor) = "by layer" Then
                If LCase(tbl_LineColor) = "by block" Then
                    .color = 0
                Else
                    .color = tbl_LineColor
                End If
            Else
                .color = 256
            End If
            If tbl_DTwAng <> 0 Then .Rotate(vIns, tbl_DTwAng)
        End With
        'DrawLine.Update
        DrawLine = Nothing
    End Function

    Private Sub TextSetting(ByVal obj As GcadText)
        With obj
            .StyleName = tbl_TextStyle
            .Layer = tbl_TextLayer
            If Not LCase(tbl_TextColor) = "by layer" Then
                If LCase(tbl_TextColor) = "by block" Then
                    .color = 0
                Else
                    .color = tbl_TextColor
                End If
            Else
                .color = 256
            End If
        End With
    End Sub

    Private Function ModifyBoders(sArea, sAdres) As MergeBoder
        Dim iSR As Integer
        Dim iER As Integer
        Dim iSC As Integer
        Dim iEC As Integer
        Dim sTmp As String

        sTmp = Mid$(sArea, 1, InStr(1, sArea, ":") - 1)
        iSR = Mid$(sTmp, 2, InStr(3, sTmp, "C") - 2)
        iSC = Mid$(sTmp, InStr(1, sTmp, "C") + 1)

        sTmp = Mid$(sArea, InStr(1, sArea, ":") + 1)
        iER = Mid$(sTmp, 2, InStr(3, sTmp, "C") - 2)
        iEC = Right$(sTmp, Len(sTmp) - InStr(1, sTmp, "C"))

        Dim ir As Integer
        Dim ic As Integer
        ir = Mid$(sAdres, 2, InStr(3, sAdres, "C") - 2)
        ic = Right$(sAdres, Len(sAdres) - InStr(1, sAdres, "C"))

        If iER > ir Then
            ModifyBoders.BL = True
            If iSR < ir Then
                ModifyBoders.TL = True
            ElseIf iSR > ir Then
                ModifyBoders.TL = False
            End If
        Else
            ModifyBoders.BL = False
            If iSR < ir Then
                ModifyBoders.TL = True
            ElseIf iSR > ir Then
                ModifyBoders.TL = False
            End If
        End If

        If iEC > ic Then
            ModifyBoders.RL = True
            If iSC < ic Then
                ModifyBoders.LL = True
            ElseIf iSC > ic Then
                ModifyBoders.LL = False
            End If
        Else
            ModifyBoders.RL = False
            If iSC < ic Then
                ModifyBoders.LL = True
            ElseIf iSC > ic Then
                ModifyBoders.LL = False
            End If
        End If
    End Function

    Private Sub DrawVerticalLine(vTmp As Object, iCol As Integer, iRow As Integer, CadCell(,) As RangeInfo)
        Dim c As Integer
        Dim r As Integer
        Dim dColSum As Double
        Dim dRowSum As Double
        Dim dColStart As Double
        Dim dColS(2) As Double
        Dim dColE(2) As Double
        Dim bExtend As Boolean

        For c = 0 To iCol
            If c <> 0 Then
                dColSum = dColSum + CadCell(0, c - 1).CellW
            End If

            For r = 0 To iRow
                dRowSum = dRowSum + CadCell(r, c).CellH

                If CadCell(r, c).xlEdgeL = False And bExtend = False Then
                    dColStart = dColStart + CadCell(r, c).CellH
                Else
                    If r < iRow Then
                        If CadCell(r + 1, c).xlEdgeL = False Then
                            If c <> 0 And c < iCol Then
                                If CadCell(0, c).ColHidden = True Then
                                    If CadCell(r + 1, c).xlEdgeR = True Then
                                        bExtend = True
                                    Else
                                        bExtend = False
                                    End If
                                End If
                            End If

                            If bExtend = False Then
                                dColS(0) = vTmp(0) + dColSum
                                dColS(1) = vTmp(1) - dColStart
                                dColE(0) = vTmp(0) + dColSum
                                dColE(1) = vTmp(1) - dRowSum
                                If Round(dColS(1) - dColE(1), 10) <> 0 Then
                                    If c = 0 Then
                                        DrawLine(dColS, dColE)
                                    Else
                                        If CadCell(0, c - 1).ColHidden = False Then
                                            DrawLine(dColS, dColE)
                                        End If
                                    End If
                                End If
                                dColStart = dRowSum
                            End If
                        End If
                    End If
                End If
            Next r

            If dColStart <> dRowSum And dColStart < dRowSum Then
                dColS(0) = vTmp(0) + dColSum
                dColS(1) = vTmp(1) - dColStart
                dColE(0) = vTmp(0) + dColSum
                dColE(1) = vTmp(1) - dRowSum
                If Round(dColS(1) - dColE(1), 10) <> 0 Then
                    If c = 0 Then
                        DrawLine(dColS, dColE)
                    Else
                        If CadCell(0, c - 1).ColHidden = False Then
                            DrawLine(dColS, dColE)
                        End If
                    End If
                End If
                bExtend = False
            End If

            If c = iCol Then
                dRowSum = 0
                dColStart = 0
                dColSum = dColSum + CadCell(0, c).CellW

                For r = 0 To iRow
                    dRowSum = dRowSum + CadCell(r, c).CellH

                    If CadCell(r, c).xlEdgeR = False Then
                        dColStart = dColStart + CadCell(r, c).CellH
                    Else
                        If r < iRow Then
                            If CadCell(r + 1, c).xlEdgeR = False Then
                                dColS(0) = vTmp(0) + dColSum
                                dColS(1) = vTmp(1) - dColStart
                                dColE(0) = vTmp(0) + dColSum
                                dColE(1) = vTmp(1) - dRowSum
                                DrawLine(dColS, dColE)
                                dColStart = dRowSum
                            End If
                        End If
                    End If
                Next r

                If dColStart <> dRowSum And dColStart < dRowSum Then
                    dColS(0) = vTmp(0) + dColSum
                    dColS(1) = vTmp(1) - dColStart
                    dColE(0) = vTmp(0) + dColSum
                    dColE(1) = vTmp(1) - dRowSum
                    DrawLine(dColS, dColE)
                End If
            End If
            dRowSum = 0
            dColStart = 0
        Next c

ErrorHandler:

    End Sub

    Private Sub DrawHorizontalLine(vTmp As Object, iCol As Integer, iRow As Integer, CadCell(,) As RangeInfo)
        Dim c As Integer
        Dim r As Integer
        Dim dColSum As Double
        Dim dRowSum As Double
        Dim dRowStart As Double
        Dim dRowS(2) As Double
        Dim dRowE(2) As Double
        Dim bExtend As Boolean

        For r = 0 To iRow
            If r <> 0 Then
                dRowSum = dRowSum + CadCell(r - 1, 0).CellH
            End If

            For c = 0 To iCol
                dColSum = dColSum + CadCell(r, c).CellW

                If CadCell(r, c).xlEdgeT = False And bExtend = False Then
                    dRowStart = dRowStart + CadCell(r, c).CellW
                Else
                    If c < iCol Then
                        If CadCell(r, c + 1).xlEdgeT = False Then
                            If r <> 0 And r < iRow Then
                                If CadCell(r, 0).RowHidden = True Then
                                    If CadCell(r, c + 1).xlEdgeB = True Then
                                        bExtend = True
                                    Else
                                        bExtend = False
                                    End If
                                End If
                            End If

                            If bExtend = False Then
                                dRowS(0) = vTmp(0) + dRowStart
                                dRowS(1) = vTmp(1) - dRowSum
                                dRowE(0) = vTmp(0) + dColSum
                                dRowE(1) = vTmp(1) - dRowSum
                                If Round(dRowS(0) - dRowE(0), 10) <> 0 Then
                                    If r = 0 Then
                                        DrawLine(dRowS, dRowE)
                                    Else
                                        If CadCell(r - 1, 0).RowHidden = False Then
                                            DrawLine(dRowS, dRowE)
                                        End If
                                    End If
                                End If
                                dRowStart = dColSum
                            End If
                        End If
                    End If
                End If
            Next c

            If dRowStart <> dColSum And dRowStart < dColSum Then
                dRowS(0) = vTmp(0) + dRowStart
                dRowS(1) = vTmp(1) - dRowSum
                dRowE(0) = vTmp(0) + dColSum
                dRowE(1) = vTmp(1) - dRowSum
                If Round(dRowS(0) - dRowE(0), 10) <> 0 Then
                    If r = 0 Then
                        DrawLine(dRowS, dRowE)
                    Else
                        If CadCell(r - 1, 0).RowHidden = False Then
                            DrawLine(dRowS, dRowE)
                        End If
                    End If
                End If
                bExtend = False
            End If

            If r = iRow Then
                dColSum = 0
                dRowStart = 0

                dRowSum = dRowSum + CadCell(r, 0).CellH

                For c = 0 To iCol
                    dColSum = dColSum + CadCell(r, c).CellW

                    If CadCell(r, c).xlEdgeB = False Then
                        dRowStart = dRowStart + CadCell(r, c).CellW
                    Else
                        If c < iCol Then
                            If CadCell(r, c + 1).xlEdgeB = False Then
                                dRowS(0) = vTmp(0) + dRowStart
                                dRowS(1) = vTmp(1) - dRowSum
                                dRowE(0) = vTmp(0) + dColSum
                                dRowE(1) = vTmp(1) - dRowSum
                                DrawLine(dRowS, dRowE)
                                dRowStart = dColSum
                            End If
                        End If
                    End If
                Next c

                If dRowStart <> dColSum And dRowStart < dColSum Then
                    dRowS(0) = vTmp(0) + dRowStart
                    dRowS(1) = vTmp(1) - dRowSum
                    dRowE(0) = vTmp(0) + dColSum
                    dRowE(1) = vTmp(1) - dRowSum
                    DrawLine(dRowS, dRowE)
                End If
            End If
            dColSum = 0
            dRowStart = 0
        Next r

ErrorHandler:

    End Sub

    Private Function GetxlVertical(ByVal sText As String) As String
        Dim dText As String
        Dim tLen As String
        Dim i As Integer

        tLen = Len(sText)
        dText = ""
        For i = 1 To tLen
            dText = dText & Mid(sText, i, 1) & vbCr
        Next

        GetxlVertical = dText
    End Function

    Private Function IsHide(sArea As String, CadCell(,) As RangeInfo) As Boolean
        Dim ir As Integer
        Dim ic As Integer

        ir = Mid$(sAll, 2, InStr(3, sAll, "C") - 2)
        ic = Right$(sAll, Len(sAll) - InStr(1, sAll, "C"))

        Dim iSR As Integer
        Dim iER As Integer
        Dim iSC As Integer
        Dim iEC As Integer
        Dim sTmp As String

        sTmp = Mid$(sArea, 1, InStr(1, sArea, ":") - 1)
        iSR = Mid$(sTmp, 2, InStr(3, sTmp, "C") - 2) - ir
        iSC = Mid$(sTmp, InStr(1, sTmp, "C") + 1) - ic

        sTmp = Mid$(sArea, InStr(1, sArea, ":") + 1)
        iER = Mid$(sTmp, 2, InStr(3, sTmp, "C") - 2) - ir
        iEC = Right$(sTmp, Len(sTmp) - InStr(1, sTmp, "C")) - ic

        Dim r As Integer
        Dim c As Integer

        IsHide = False
        For c = iSC To iEC
            For r = iSR To iER
                If CadCell(r, c).ColHidden = True Or _
                   CadCell(r, c).RowHidden = True Then
                    IsHide = True
                    Exit For
                End If
            Next
        Next

        If CadCell(0, iEC).ColHidden = True Then
            IsHide = False
        End If
        If CadCell(iER, 0).RowHidden = True Then
            IsHide = False
        End If
    End Function

    Private Sub WriteText(vTmp As Object, iCol As Integer, iRow As Integer, CadCell(,) As RangeInfo)
        Dim c As Integer
        Dim r As Integer
        Dim dColSum As Double
        Dim dRowSum As Double
        Dim dIns(2) As Double
        Dim sText As String
        Dim dTextH As String
        Dim dMergeH As Double
        Dim dMergeW As Double
        Dim iStart As Integer
        Dim iEnd As Integer
        Dim sTmpArea As String
        Dim sTmp As String
        Dim m As Integer
        Dim oDText As GcadText
        Dim dFitH As Double
        Dim dFitV As Double
        Dim iTab As Integer
        Dim vArray As Object
        Dim k As Integer
        Dim dModifyV As Double
        Dim dModifyH As Double
        Dim iMid As Integer
        Dim bWrite As Boolean
        Dim iMax As Integer

        Dim dTScale As Double
        dTScale = tbl_TextHig / tbl_ExcelHig

        Dim ir As Integer
        Dim ic As Integer

        ir = Mid$(sAll, 2, InStr(3, sAll, "C") - 2)
        ic = Right$(sAll, Len(sAll) - InStr(1, sAll, "C"))

        For c = 0 To iCol
            If c <> 0 Then
                dColSum = dColSum + CadCell(0, c - 1).CellW
            End If
            For r = 0 To iRow
                If r <> 0 Then
                    dRowSum = dRowSum + CadCell(r - 1, c).CellH
                End If

                sText = RTrim(CadCell(r, c).Text)
                If tbl_ChkSpace = True Then
                    sText = DeleteSpace(sText)
                End If

                If CadCell(r, c).Merge = True Then
                    If sText = "" Then
                        If IsHide(CadCell(r, c).MergeArea, CadCell) = True Then
                            sText = CadCell(r, c).MergeText
                        End If
                    End If
                End If

                iTab = CadCell(r, c).TextTab

                If sText <> "" Then
                    dTextH = CadCell(r, c).TextH * dTScale
                    dTextH = dTextH

                    If CadCell(r, c).TextOrient = 4166 Then
                        sText = GetxlVertical(sText)
                    End If

                    If CadCell(r, c).Merge = True Then
                        sTmpArea = CadCell(r, c).MergeArea
                        sTmp = Mid$(sTmpArea, 1, InStr(1, sTmpArea, ":") - 1)
                        iStart = Mid$(sTmp, InStr(1, sTmp, "C") + 1) - ic
                        sTmp = Mid$(sTmpArea, InStr(1, sTmpArea, ":") + 1)
                        iEnd = Right$(sTmp, Len(sTmp) - InStr(1, sTmp, "C")) - ic
                        If iStart <> iEnd Then
                            For m = iStart To iEnd
                                If CadCell(r, m).ColHidden = False Then
                                    dMergeW = dMergeW + CadCell(r, m).CellW
                                End If
                            Next
                        ElseIf iStart = iEnd Then
                            dMergeW = dMergeW + CadCell(r, c).CellW
                        End If

                        sTmpArea = CadCell(r, c).MergeArea
                        sTmp = Mid$(sTmpArea, 1, InStr(1, sTmpArea, ":") - 1)
                        iStart = Mid$(sTmp, 2, InStr(3, sTmp, "C") - 2) - ir
                        sTmp = Mid$(sTmpArea, InStr(1, sTmpArea, ":") + 1)
                        iEnd = Mid$(sTmp, 2, InStr(3, sTmp, "C") - 2) - ir
                        If iStart <> iEnd Then
                            For m = iStart To iEnd
                                If CadCell(m, c).RowHidden = False Then
                                    dMergeH = dMergeH + CadCell(m, c).CellH
                                End If
                            Next
                        ElseIf iStart = iEnd Then
                            dMergeH = dMergeH + CadCell(r, c).CellH
                        End If

                    Else
                        dMergeW = dMergeW + CadCell(r, c).CellW
                        dMergeH = dMergeH + CadCell(r, c).CellH
                    End If

                    Select Case CadCell(r, c).TextHAdj
                        Case "L"
                            dIns(0) = vTmp(0) + dColSum + (dTextH / 2 + dTextH * 2 * iTab)
                        Case "C"
                            dIns(0) = vTmp(0) + (dColSum + dMergeW / 2)
                        Case "R"
                            dIns(0) = vTmp(0) + (dColSum + dMergeW) - (dTextH / 2 + dTextH * 2 * iTab)
                    End Select
                    dFitH = dMergeW - (dTextH + dTextH * 2 * iTab)

                    Select Case CadCell(r, c).TextVAdj
                        Case "T"
                            dIns(1) = vTmp(1) - (dRowSum) - dTextH / 3
                        Case "C"
                            dIns(1) = vTmp(1) - (dRowSum + dMergeH / 2)
                        Case "B"
                            dIns(1) = vTmp(1) - (dRowSum + dMergeH) + dTextH / 3
                    End Select
                    dFitV = dMergeH - dTextH

                    dIns(2) = 0.0#

                    bWrite = False

                    If CadCell(r, 0).RowHidden = False Then
                        If CadCell(0, c).ColHidden = False Then
                            If InStr(1, sText, vbLf) <> 0 Then
                                dModifyH = dIns(0)
                                dModifyV = dIns(1)
                                vArray = Split(sText, vbLf)
                                iMax = UBound(vArray)

                                If iMax Mod 2 = 0 Then
                                    iMid = iMax / 2 - 1
                                    bWrite = True
                                    If Trim$(vArray(iMax / 2)) <> "" Then
                                        oDText = WorkSpace.AddText(Trim$(vArray(iMax / 2)), dIns, dTextH)
                                        TableText(r, c, dIns, oDText, CadCell, dFitH, dFitV)
                                    End If
                                Else
                                    iMid = Fix(iMax / 2)
                                End If

                                For k = iMid To 0 Step -1
                                    Select Case CadCell(r, c).TextOrient
                                        Case 0, 4166
                                            If k = iMid Then
                                                If iMax Mod 2 = 0 Then
                                                    dIns(1) = dIns(1) + dTextH + (dTextH / 2)
                                                Else
                                                    dIns(1) = dIns(1) + dTextH * (4 / 6)
                                                End If
                                            Else
                                                dIns(1) = dIns(1) + dTextH + (dTextH / 2)
                                            End If
                                        Case 90
                                            If k = iMid Then
                                                If iMax Mod 2 = 0 Then
                                                    dIns(0) = dIns(0) - (dTextH + (dTextH / 2))
                                                Else
                                                    dIns(0) = dIns(0) - dTextH * (4 / 6)
                                                End If
                                            Else
                                                dIns(0) = dIns(0) - (dTextH + (dTextH / 2))
                                            End If
                                        Case 270
                                            If k = iMid Then
                                                If iMax Mod 2 = 0 Then
                                                    dIns(0) = dIns(0) + dTextH + (dTextH / 2)
                                                Else
                                                    dIns(0) = dIns(0) + dTextH * (4 / 6)
                                                End If
                                            Else
                                                dIns(0) = dIns(0) + dTextH + (dTextH / 2)
                                            End If
                                    End Select
                                    If sText <> "" Then
                                        oDText = WorkSpace.AddText(Trim$(vArray(k)), dIns, dTextH)
                                        TableText(r, c, dIns, oDText, CadCell, dFitH, dFitV)
                                    End If
                                Next

                                dIns(0) = dModifyH
                                dIns(1) = dModifyV
                                If bWrite Then
                                    iMid = iMid + 2
                                Else
                                    iMid = iMid + 1
                                End If

                                For k = iMid To iMax
                                    Select Case CadCell(r, c).TextOrient
                                        Case 0, 4166
                                            If k = iMid Then
                                                If iMax Mod 2 = 0 Then
                                                    dIns(1) = dIns(1) - (dTextH + (dTextH / 2))
                                                Else
                                                    dIns(1) = dIns(1) - dTextH * (4 / 6)
                                                End If
                                            Else
                                                dIns(1) = dIns(1) - (dTextH + (dTextH / 2))
                                            End If
                                        Case 90
                                            If k = iMid Then
                                                If iMax Mod 2 = 0 Then
                                                    dIns(0) = dIns(0) + dTextH + (dTextH / 2)
                                                Else
                                                    dIns(0) = dIns(0) + dTextH * (4 / 6)
                                                End If
                                            Else
                                                dIns(0) = dIns(0) + dTextH + (dTextH / 2)
                                            End If
                                        Case 270
                                            If k = iMid Then
                                                If iMax Mod 2 = 0 Then
                                                    dIns(0) = dIns(0) - (dTextH + (dTextH / 2))
                                                Else
                                                    dIns(0) = dIns(0) - dTextH * (4 / 6)
                                                End If
                                            Else
                                                dIns(0) = dIns(0) - (dTextH + (dTextH / 2))
                                            End If
                                    End Select
                                    If sText <> "" Then
                                        oDText = WorkSpace.AddText(Trim$(vArray(k)), dIns, dTextH)
                                        TableText(r, c, dIns, oDText, CadCell, dFitH, dFitV)
                                    End If
                                Next
                            Else
                                If sText <> "" Then
                                    oDText = WorkSpace.AddText(sText, dIns, dTextH)
                                    TableText(r, c, dIns, oDText, CadCell, dFitH, dFitV)
                                End If
                            End If
                        End If
                    End If
                End If 'If sText <> "" Then
                dMergeW = 0
                dMergeH = 0
            Next r
            dRowSum = 0
        Next c

ErrorHandler:
        oDText = Nothing
    End Sub

    Private Sub TableText(r As Integer, c As Integer, dIns() As Double, _
                          oDText As GcadEntity, CadCell(,) As RangeInfo, dFitH As Double, dFitV As Double)
        On Error Resume Next

        Dim vMin As Object = Nothing
        Dim vMax As Object = Nothing

        With oDText
            .GetBoundingBox(vMin, vMax)
            If Err.Number Then
                Err.Clear()
                Exit Sub
            End If

            Select Case CadCell(r, c).TextOrient
                Case 0, 4166
                    Select Case CadCell(r, c).TextHAdj
                        Case "L"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentTopLeft
                                Case "C"
                                    .Alignment = acAlignmentMiddleLeft
                                Case "B"
                                    .Alignment = acAlignmentBottomLeft
                            End Select
                        Case "C"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentTopCenter
                                Case "C"
                                    .Alignment = acAlignmentMiddleCenter
                                Case "B"
                                    .Alignment = acAlignmentBottomCenter
                            End Select
                        Case "R"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentTopRight
                                Case "C"
                                    .Alignment = acAlignmentMiddleRight
                                Case "B"
                                    .Alignment = acAlignmentBottomRight
                            End Select
                    End Select
                Case 90
                    .Rotation = D2R(90)
                    Select Case CadCell(r, c).TextHAdj
                        Case "L"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentTopRight
                                Case "C"
                                    .Alignment = acAlignmentTopCenter
                                Case "B"
                                    .Alignment = acAlignmentTopLeft
                            End Select
                        Case "C"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentMiddleRight
                                Case "C"
                                    .Alignment = acAlignmentMiddleCenter
                                Case "B"
                                    .Alignment = acAlignmentMiddleLeft
                            End Select
                        Case "R"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentBottomRight
                                Case "C"
                                    .Alignment = acAlignmentBottomCenter
                                Case "B"
                                    .Alignment = acAlignmentBottomLeft
                            End Select
                    End Select
                Case 270
                    .Rotation = D2R(270)
                    Select Case CadCell(r, c).TextHAdj
                        Case "L"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentBottomLeft
                                Case "C"
                                    .Alignment = acAlignmentBottomCenter
                                Case "B"
                                    .Alignment = acAlignmentBottomRight
                            End Select
                        Case "C"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentMiddleLeft
                                Case "C"
                                    .Alignment = acAlignmentMiddleCenter
                                Case "B"
                                    .Alignment = acAlignmentMiddleRight
                            End Select
                        Case "R"
                            Select Case CadCell(r, c).TextVAdj
                                Case "T"
                                    .Alignment = acAlignmentTopLeft
                                Case "C"
                                    .Alignment = acAlignmentTopCenter
                                Case "B"
                                    .Alignment = acAlignmentTopRight
                            End Select
                    End Select
            End Select

            .TextAlignmentPoint = dIns
            .ScaleFactor = tbl_TextWid
            If tbl_ChkFit = True Then
                If CadCell(r, c).TextOrient <> 0 Then
                    If vMax(0) - vMin(0) > dFitV Then
                        .ScaleFactor = Round(dFitV / (vMax(0) - vMin(0)), 1)
                    End If
                Else
                    If vMax(0) - vMin(0) > dFitH Then
                        .ScaleFactor = Round(dFitH / (vMax(0) - vMin(0)), 1)
                    End If
                End If
            End If
            If tbl_DTwAng <> 0 Then .Rotate(vIns, tbl_DTwAng)
        End With

        Dim iXType(3) As Integer
        Dim vXData(3) As Object
        Dim bXdata As Boolean
        bXdata = tbl_ChkXdata
        If bXdata Then
            iXType(0) = 1001
            vXData(0) = APPNAME
            iXType(1) = 1000
            vXData(1) = sExlName 'sBook & "|" & oSheet.Name
            iXType(2) = 1070
            vXData(2) = CadCell(r, c).CellRow
            iXType(3) = 1071
            vXData(3) = CadCell(r, c).CellCol
            oDText.SetXData(iXType, vXData)
        End If

        TextSetting(oDText)
    End Sub

    Public Sub ExcelToCAD()
        Dim GcadCi As GcadCircle
        Dim GcadLyr As GcadLayer
        Dim CurrLyr As GcadLayer
        Dim TextObj As Object
        Dim ARR As Object
        Dim TxtStyle As GcadTextStyle
        Dim oExcel As Object
        Dim oBook As Object
        Dim oSheet As Object
        Dim oCell As Object

        InitLibrary()

        On Error Resume Next

        oExcel = GetObject(, "Excel.Application")
        If oExcel Is Nothing Then
            oExcel = CreateObject("Excel.Application")
            oBook = oExcel.Workbooks.Add
            oSheet = oBook.Worksheets.Item(1)
        End If
        If oExcel Is Nothing Then
            Err.Clear()
            MsgBox("실행되는 Excel 프로그램이 없습니다", vbInformation, tbl_Title)
            Exit Sub
        End If

        With oExcel
            oBook = .ActiveWorkbook
            oSheet = .ActiveSheet
        End With

        'If oSheet.ProtectContents Then
        '    MsgBox "시트가 보호되어 있거나 Excel에 열린 문서가 없습니다.", vbInformation, tbl_Title
        '    Exit Sub
        'End If

        ' -4140 : minimized
        ' -4137 : maximized
        ' -4143 : normal
        'Me.hide()
        oCell = Nothing
        With oExcel
            Dim iState As Integer
            iState = .WindowState

            If iState = -4140 Then
                .WindowState = -4143
            End If

            .Assistant.Visible = False

            .Visible = True
            'AppActivate(GcadApp.Caption)
            'AppActivate.Caption()

            On Error Resume Next
            oCell = .InputBox("CAD로 가져올 표의 범위을 선택하세요", Title:=tbl_Title, Type:=8, Default:=.Selection.Address)
        End With

        On Error GoTo ErrorHandler
        If oCell Is Nothing Then
            oExcel.WindowState = -4140
            GoTo ErrorHandler
        End If

        '워크북 이름과 시트이름
        Dim sBook As String
        sBook = oBook.name
        sBook.Replace(".xls", "")
        sExlName = sBook & "|" & oSheet.name

        oExcel.WindowState = -4140
        GcadApp.Visible = True
        'AppActivate(GcadApp.Caption)

        vIns = GcadUtil.GetPoint(, vbCr & "표를 삽입 할 점 지정:")
        If IsNothing(vIns) Then GoTo ErrorHandler

        Dim iCol As Integer
        Dim iRow As Integer
        With oCell
            iCol = .Columns.Count - 1
            iRow = .Rows.Count - 1
            sAll = .Address(ReferenceStyle:=xlR1C1, ColumnAbsolute:=True, RowAbsolute:=True)
            If InStr(1, sAll, ":") <> 0 Then
                sAll = Mid$(sAll, 1, InStr(1, sAll, ":") - 1)
            End If
            If iCol = 0 And iRow = 0 Then
                If oCell.MergeCells = True Then
                    'ct.OneCell(oCell.MergeArea.Address(ReferenceStyle:=xlR1C1, ColumnAbsolute:=True, RowAbsolute:=True), iRow, iCol)
                End If
            End If
        End With

        Dim dScale As Double
        dScale = tbl_TextHig / tbl_ExcelHig * 1.5

        Dim c As Integer
        Dim r As Integer
        Dim CadCell(,) As RangeInfo

        ReDim CadCell(iRow, iCol)
        Dim oTmpCell As Object
        Dim sBoder As MergeBoder
        Dim sAddress As String
        Dim dUserH As Double
        Dim bUserH As Boolean
        Dim dUserW As Double
        Dim bUserW As Boolean

        dUserH = CInt(tbl_TableHig)
        dUserW = CInt(tbl_TableWid)
        bUserH = tbl_OptUserH
        bUserW = tbl_OptUserW

        For c = 0 To iCol
            For r = 0 To iRow
                oTmpCell = oCell.Cells(r + 1, c + 1)

                sAddress = oTmpCell.Address(ReferenceStyle:=xlR1C1, ColumnAbsolute:=True, RowAbsolute:=True)

                With oTmpCell
                    If bUserW Then
                        CadCell(r, c).CellW = dUserW
                    ElseIf tbl_OptIntW Then
                        CadCell(r, c).CellW = CInt(.Columns.Width * dScale)
                    Else
                        CadCell(r, c).CellW = .Columns.Width * dScale
                    End If

                    If bUserH Then
                        CadCell(r, c).CellH = dUserH
                    ElseIf tbl_OptIntH Then
                        CadCell(r, c).CellH = CInt(.Rows.Height * dScale)
                    Else
                        CadCell(r, c).CellH = .Rows.Height * dScale
                    End If

                    CadCell(r, c).RowHidden = .Rows.EntireRow.Hidden
                    CadCell(r, c).ColHidden = .Columns.EntireColumn.Hidden
                    If oTmpCell.MergeCells = True Then
                        CadCell(r, c).Merge = True
                        CadCell(r, c).MergeArea = .MergeArea.Address(ReferenceStyle:=xlR1C1, _
                                                   ColumnAbsolute:=True, RowAbsolute:=True)
                        'CadCell(r, c).MergeText = oSheet.Range(ct.GetMergeText(.MergeArea.Address)).Text
                        sBoder = ModifyBoders(CadCell(r, c).MergeArea, sAddress)
                    End If

                    CadCell(r, c).Text = .Text
                    CadCell(r, c).CellRow = .Row
                    CadCell(r, c).CellCol = .Column

                    On Error Resume Next
                    CadCell(r, c).TextH = .Font.Size
                    If Err.Number Then
                        'Font.Size가 Null 인 경우
                        Err.Clear()
                        CadCell(r, c).TextH = 11.0#
                    End If

                    CadCell(r, c).CellFormat = .NumberFormat

                    On Error GoTo ErrorHandler
                    Select Case .HorizontalAlignment
                        Case -4130
                            CadCell(r, c).TextHAdj = "L"
                        Case -4131
                            CadCell(r, c).TextHAdj = "L"
                        Case -4108
                            CadCell(r, c).TextHAdj = "C"
                        Case -4152
                            CadCell(r, c).TextHAdj = "R"
                        Case 1
                            If IsNumeric(CadCell(r, c).Text) Then
                                CadCell(r, c).TextHAdj = "R"
                            Else
                                CadCell(r, c).TextHAdj = "L"
                            End If
                        Case Else
                            CadCell(r, c).TextHAdj = "C"
                    End Select

                    Select Case .VerticalAlignment
                        Case -4160
                            CadCell(r, c).TextVAdj = "T"
                        Case -4108
                            CadCell(r, c).TextVAdj = "C"
                        Case -4107
                            CadCell(r, c).TextVAdj = "B"
                        Case 1
                            CadCell(r, c).TextVAdj = "C"
                        Case Else
                            CadCell(r, c).TextVAdj = "C"
                    End Select

                    Select Case .Orientation
                        Case -4166
                            CadCell(r, c).TextOrient = 4166
                        Case -4171
                            CadCell(r, c).TextOrient = 90
                        Case -4170
                            CadCell(r, c).TextOrient = 270
                        Case Else
                            CadCell(r, c).TextOrient = 0
                    End Select

                    CadCell(r, c).TextTab = .IndentLevel

                    If .Borders(xlEdgeRight).LineStyle <> -4142 Then
                        If sBoder.RL = False Then
                            CadCell(r, c).xlEdgeR = True
                        Else
                            CadCell(r, c).xlEdgeR = False
                        End If
                    End If
                    If .Borders(xlEdgeLeft).LineStyle <> -4142 Then
                        If sBoder.LL = False Then
                            CadCell(r, c).xlEdgeL = True
                        Else
                            CadCell(r, c).xlEdgeL = False
                        End If
                    End If
                    If .Borders(xlEdgeTop).LineStyle <> -4142 Then
                        If sBoder.TL = False Then
                            CadCell(r, c).xlEdgeT = True
                        Else
                            CadCell(r, c).xlEdgeT = False
                        End If
                    End If
                    If .Borders(xlEdgeBottom).LineStyle <> -4142 Then
                        If sBoder.BL = False Then
                            CadCell(r, c).xlEdgeB = True
                        Else
                            CadCell(r, c).xlEdgeB = False
                        End If
                    End If
                End With
                sBoder.RL = False
                sBoder.LL = False
                sBoder.BL = False
                sBoder.TL = False
            Next r
        Next c

        If tbl_ChkTable = True Then
            DrawVerticalLine(vIns, iCol, iRow, CadCell)
            DrawHorizontalLine(vIns, iCol, iRow, CadCell)
        End If

        If tbl_ChkText = True Then
            WriteText(vIns, iCol, iRow, CadCell)
        End If

        UninitLibrary()

        oExcel = Nothing
        oBook = Nothing
        oSheet = Nothing
        oCell = Nothing
        'UnLoadMyDLL()
        'Unload(Me)

        Exit Sub

ErrorHandler:

        On Error Resume Next

        UninitLibrary()

        oExcel = Nothing
        oBook = Nothing
        oSheet = Nothing
        oCell = Nothing

        If Err.Number Then
            MsgBox(Err.Description)
            Err.Clear()
        End If

        'Unload(Me)
    End Sub

    Private Sub DeleteZeroLine(vSSpnt As Object, vSEpnt As Object)
        On Error Resume Next
        Dim sLockLayer As String
        sLockLayer = LockBackUp()

        Dim dLength As Double
        dLength = 0.00001

        Dim oSel As GcadSelectionSet
        Dim iGcode(0) As Integer
        Dim vData(0) As Object
        Dim iCnt As Long
        oSel = CreateSelSet("Temp")
        iGcode(0) = 0
        vData(0) = "line,lwpolyline,polyline"
        oSel.Select(gcSelectionSetCrossing, vSSpnt, vSEpnt, iGcode, vData)

        iCnt = oSel.Count
        If iCnt = 0 Then
            Call LockRestore(sLockLayer)
            Exit Sub
        End If

        Dim oEnt As GcadEntity
        Dim iDelCnt As Long
        For Each oEnt In oSel
            'If GetQueueStatus(QS_INPUT) <> 0 Then System.Windows.Forms.Application.DoEvents()
            With oEnt
                If .Length < dLength Then
                    .Delete()
                    iDelCnt = iDelCnt + 1
                End If
            End With
        Next

        Call LockRestore(sLockLayer)
    End Sub

    Private Function VHCoordinate(dblS() As Double, dblE() As Double, dTol As Double)
        Dim iCnt As Integer
        Dim sAdd As String
        Dim sDec As String
        Dim iDec As Integer
        sDec = "0.000000"
        iDec = 6

        On Error Resume Next

        If IsEqual(dblS(0), dblE(0), dTol) Then
            If dblS(0) >= vSEpnt(0) And dblS(0) <= vSSpnt(0) And _
               dblE(0) >= vSEpnt(0) And dblE(0) <= vSSpnt(0) Then
                iCnt = UBound(vTmpCol)

                If dblS(1) < dblE(1) Then
                    dCol(0) = Round(dblE(0), iDec)
                    dCol(1) = Round(dblE(1), iDec)
                    dCol(2) = Round(dblS(0), iDec)
                    dCol(3) = Round(dblS(1), iDec)
                Else
                    dCol(0) = Round(dblS(0), iDec)
                    dCol(1) = Round(dblS(1), iDec)
                    dCol(2) = Round(dblE(0), iDec)
                    dCol(3) = Round(dblE(1), iDec)
                End If

                sAdd = Format(dCol(0), sDec) & Format(dCol(1), sDec) & _
                       Format(dCol(2), sDec) & Format(dCol(3), sDec)
                col.Add(0, sAdd)

                If Err.Number Then
                    Err.Clear()
                Else
                    vTmpCol(iCnt) = dCol
                    ReDim Preserve vTmpCol(iCnt + 1)
                End If
            End If

        ElseIf IsEqual(dblS(1), dblE(1), dTol) Then
            If dblS(1) <= vSSpnt(1) And dblS(1) >= vSEpnt(1) And _
               dblE(1) <= vSSpnt(1) And dblE(1) >= vSEpnt(1) Then

                iCnt = UBound(vTmpRow)
                If dblS(0) > dblE(0) Then
                    dRow(0) = Round(dblE(0), iDec)
                    dRow(1) = Round(dblE(1), iDec)
                    dRow(2) = Round(dblS(0), iDec)
                    dRow(3) = Round(dblS(1), iDec)
                Else
                    dRow(0) = Round(dblS(0), iDec)
                    dRow(1) = Round(dblS(1), iDec)
                    dRow(2) = Round(dblE(0), iDec)
                    dRow(3) = Round(dblE(1), iDec)
                End If

                sAdd = Format(dRow(0), sDec) & Format(dRow(1), sDec) & _
                       Format(dRow(2), sDec) & Format(dRow(3), sDec)
                col.Add(0, sAdd)

                If Err.Number Then
                    Err.Clear()
                Else
                    vTmpRow(iCnt) = dRow
                    ReDim Preserve vTmpRow(iCnt + 1)
                End If
            End If
        End If

    End Function

    Private Sub DetachLine(oSelLine As GcadSelectionSet, dTol As Double)
        Dim iCnt As Integer
        iCnt = oSelLine.Count

        Dim oTmp As GcadEntity
        Dim i As Integer
        Dim k As Integer
        Dim vSpnt As Object
        Dim vEpnt As Object
        Dim dblS(1) As Double
        Dim dblE(1) As Double
        Dim sLayer As String
        Dim bLock As Boolean

        ReDim vTmpCol(0)
        ReDim vTmpRow(0)
        bLock = False

        For i = 0 To iCnt - 1
            oTmp = oSelLine.Item(i)
            Select Case oTmp.ObjectName
                Case "AcDbLine"
                    vSpnt = oTmp.StartPoint
                    vEpnt = oTmp.EndPoint
                    dblS(0) = vSpnt(0)
                    dblS(1) = vSpnt(1)
                    dblE(0) = vEpnt(0)
                    dblE(1) = vEpnt(1)

                    VHCoordinate(dblS, dblE, dTol)

                Case Else
                    vExplode = oTmp.Explode
                    sLayer = oTmp.Layer

                    If GcadDoc.Layers(sLayer).Lock Then
                        GcadDoc.Layers(sLayer).Lock = False
                        bLock = True
                    End If

                    For k = 0 To UBound(vExplode)
                        If vExplode(k).ObjectName = "AcDbLine" Then
                            vSpnt = vExplode(k).StartPoint
                            vEpnt = vExplode(k).EndPoint
                            dblS(0) = vSpnt(0)
                            dblS(1) = vSpnt(1)
                            dblE(0) = vEpnt(0)
                            dblE(1) = vEpnt(1)

                            VHCoordinate(dblS, dblE, dTol)
                        End If

                        vExplode(k).Delete()
                    Next
                    If bLock Then
                        GcadDoc.Layers(sLayer).Lock = True
                    End If
            End Select
            bLock = False
        Next

        ReDim Preserve vTmpCol(UBound(vTmpCol) - 1)
        ReDim Preserve vTmpRow(UBound(vTmpRow) - 1)
    End Sub

    'long DeleteDupEntity(LPDISPATCH * oSel, BSTR * sObj, BOOL * bLayer, BOOL * bZ, short * iDec, BSTR * sLayer)
    Private Function DeleteDupEntity(ByRef oSel As GcadSelectionSet, ByVal sObj As String, ByVal bLayer As Boolean, _
                        ByVal bZ As Boolean, ByVal iDec As Integer, Optional ByVal sLayer As String = "") As Long
        'DeleteDupEntity = dll.DeleteDupEntity(oSel, sObj, bLayer, bZ, iDec, sLayer)
        DeleteDupEntity = 0
    End Function

    Private Function GetLargeHeight(ByVal oSel As GcadSelectionSet) As Double
        'GetLargeHeight = ct.GetLargeHeight(oSel)

        Dim i As Long
        Dim curHig, maxHig As Double
        Dim minPnt As Object = Nothing
        Dim maxPnt As Object = Nothing

        maxHig = 0
        For i = 0 To oSel.Count - 1
            With oSel.Item(i)
                If .ObjectName = "AcDbText" Then
                    curHig = .Height
                ElseIf .ObjectName = "AcDbMText" Then
                    .GetBoundingBox(minPnt, maxPnt)
                    curHig = maxPnt(1) - minPnt(1)
                Else
                    curHig = 0
                End If
            End With
            If maxHig < curHig Then
                maxHig = curHig
            End If
        Next

        GetLargeHeight = maxHig
    End Function

    '    VARIANT SortTextTable(LPDISPATCH * oSel, double * dTol, double * dTWAng)
    Private Sub SortTextTable(ByRef oSel As GcadSelectionSet, ByVal dTol As Double, Optional ByVal dTWAng As Double = 0)
        'func.SortTextTable(oSel, dTol)
    End Sub

    Private Sub SortListZ(ByRef vList As Object, ByVal dTol As Double, Optional ByVal dTWAng As Double = 0)
        'func.SortListZ(vList, dTol)
        Dim tmpDir As String = GetTempPath()
        Dim inFile As String = tmpDir & "\magic.in"
        Dim outFile As String = tmpDir & "\magic.out"

        FileOpen(1, inFile, OpenMode.Output)
        Print(1, "SLZ" & vbNewLine) ' SortListZ

        Dim uBnd As Integer = UBound(vList)
        Print(1, uBnd)

        Dim pDat(3) As Double
        Dim i, j As Integer
        For i = 0 To uBnd
            pDat = vList(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        Print(1, dTol)
        FileClose(1)

        Dim exeCmd As String = "MagicLink.exe " & Chr(34) & inFile & Chr(34) & " " & Chr(34) & outFile & Chr(34)
        Shell(exeCmd, AppWinStyle.Hide, True)

        FileOpen(2, outFile, OpenMode.Input)
        Input(2, uBnd)
        ReDim vList(uBnd)

        For i = 0 To uBnd
            For j = 0 To 3
                Input(2, pDat(j))
            Next j
            vList(i) = pDat
        Next i

        FileClose(2)
    End Sub

    Private Sub SortListN(ByRef vList As Object, ByVal dTol As Double, Optional ByVal dTWAng As Double = 0)
        'func.SortListN(vList, dTol)
        Dim tmpDir As String = GetTempPath()
        Dim inFile As String = tmpDir & "\magic.in"
        Dim outFile As String = tmpDir & "\magic.out"

        FileOpen(1, inFile, OpenMode.Output)
        Print(1, "SLN" & vbNewLine) ' SortListN

        Dim uBnd As Integer = UBound(vList)
        Print(1, uBnd)

        Dim pDat(3) As Double
        Dim i, j As Integer
        For i = 0 To uBnd
            pDat = vList(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        Print(1, dTol)
        FileClose(1)

        Dim exeCmd As String = "MagicLink.exe " & Chr(34) & inFile & Chr(34) & " " & Chr(34) & outFile & Chr(34)
        Shell(exeCmd, AppWinStyle.Hide, True)

        FileOpen(2, outFile, OpenMode.Input)
        Input(2, uBnd)
        ReDim vList(uBnd)

        For i = 0 To uBnd
            For j = 0 To 3
                Input(2, pDat(j))
            Next j
            vList(i) = pDat
        Next i

        FileClose(2)
    End Sub

    Private Sub SortListIN(ByRef vList As Object, ByVal dTol As Double, Optional ByVal dTWAng As Double = 0)
        'func.SortListIN(vList, dTol)
        Dim tmpDir As String = GetTempPath()
        Dim inFile As String = tmpDir & "\magic.in"
        Dim outFile As String = tmpDir & "\magic.out"

        FileOpen(1, inFile, OpenMode.Output)
        Print(1, "SLI" & vbNewLine) ' SortListIN

        Dim uBnd As Integer = UBound(vList)
        Print(1, uBnd)

        Dim pDat(3) As Double
        Dim i, j As Integer
        For i = 0 To uBnd
            pDat = vList(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        Print(1, dTol)
        FileClose(1)

        Dim exeCmd As String = "MagicLink.exe " & Chr(34) & inFile & Chr(34) & " " & Chr(34) & outFile & Chr(34)
        Shell(exeCmd, AppWinStyle.Hide, True)

        FileOpen(2, outFile, OpenMode.Input)
        Input(2, uBnd)
        ReDim vList(uBnd)

        For i = 0 To uBnd
            For j = 0 To 3
                Input(2, pDat(j))
            Next j
            vList(i) = pDat
        Next i

        FileClose(2)
    End Sub

    ' Set Select Region Point to RightUpper - LeftLower
    Private Sub RegionRULD(ByRef vFirst As Object, ByRef vSecond As Object)
        Dim vTmp As Double

        If vFirst(0) < vSecond(0) Then
            vTmp = vFirst(0)
            vFirst(0) = vSecond(0)
            vSecond(0) = vTmp
        End If
        If vFirst(1) < vSecond(1) Then
            vTmp = vFirst(1)
            vFirst(1) = vSecond(1)
            vSecond(1) = vTmp
        End If
    End Sub

    Private Function GetTableRX(ByRef vCol() As Object, ByVal c As Integer, ByVal dTol As Double) As Double
        'GetTableRX = ct.GetTableRX(vCol, c, dTol)
        Dim tmpDir As String = GetTempPath()
        Dim inFile As String = tmpDir & "\magic.in"
        Dim outFile As String = tmpDir & "\magic.out"

        FileOpen(1, inFile, OpenMode.Output)
        Print(1, "TRX" & vbNewLine) ' GetTableRX

        Dim uBnd As Integer = UBound(vCol)
        Print(1, uBnd)

        Dim pDat(3) As Double
        Dim i, j As Integer
        For i = 0 To uBnd
            pDat = vCol(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        Print(1, c)
        Print(1, dTol)
        FileClose(1)

        Dim exeCmd As String = "MagicLink.exe " & Chr(34) & inFile & Chr(34) & " " & Chr(34) & outFile & Chr(34)
        Shell(exeCmd, AppWinStyle.Hide, True)

        FileOpen(2, outFile, OpenMode.Input)
        Dim dVal As Double
        Input(2, dVal)
        FileClose(2)

        GetTableRX = dVal
    End Function

    Private Function GetTableRY(ByRef vRow() As Object, ByVal r As Integer, ByVal dTol As Double) As Double
        'GetTableRY = ct.GetTableRY(vRow, r, dTol)
        Dim tmpDir As String = GetTempPath()
        Dim inFile As String = tmpDir & "\magic.in"
        Dim outFile As String = tmpDir & "\magic.out"

        FileOpen(1, inFile, OpenMode.Output)
        Print(1, "TRY" & vbNewLine) ' GetTableRY

        Dim uBnd As Integer = UBound(vRow)
        Print(1, uBnd)

        Dim pDat(3) As Double
        Dim i, j As Integer
        For i = 0 To uBnd
            pDat = vRow(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        Print(1, r)
        Print(1, dTol)
        FileClose(1)

        Dim exeCmd As String = "MagicLink.exe " & Chr(34) & inFile & Chr(34) & " " & Chr(34) & outFile & Chr(34)
        Shell(exeCmd, AppWinStyle.Hide, True)

        FileOpen(2, outFile, OpenMode.Input)
        Dim dVal As Double
        Input(2, dVal)
        FileClose(2)

        GetTableRY = dVal
    End Function

    Private Function IsColLine(ByVal vTmpCol As Object, ByVal vTmpRow As Object, ByVal k As Integer, ByVal iSta As Integer, ByVal iEnd As Integer, ByVal dTol As Double) As Boolean
        'IsColLine = ct.IsColLine(vTmpCol, vTmpRow, k, iSta, iEnd, dTol)
        Dim tmpDir As String = GetTempPath()
        Dim inFile As String = tmpDir & "\magic.in"
        Dim outFile As String = tmpDir & "\magic.out"

        FileOpen(1, inFile, OpenMode.Output)
        Print(1, "ICL" & vbNewLine) ' IsColLine

        Dim uBnd As Integer = UBound(vTmpCol)
        Print(1, uBnd)

        Dim pDat(3) As Double
        Dim i, j As Integer
        For i = 0 To uBnd
            pDat = vTmpCol(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        uBnd = UBound(vTmpRow)
        Print(1, uBnd)

        For i = 0 To uBnd
            pDat = vTmpRow(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        Print(1, k)
        Print(1, iSta)
        Print(1, iEnd)
        Print(1, dTol)
        FileClose(1)

        Dim exeCmd As String = "MagicLink.exe " & Chr(34) & inFile & Chr(34) & " " & Chr(34) & outFile & Chr(34)
        Shell(exeCmd, AppWinStyle.Hide, True)

        FileOpen(2, outFile, OpenMode.Input)
        Dim iVal As Integer
        Dim bVal As Boolean
        Input(2, iVal)
        If iVal <> 0 Then
            bVal = True
        Else
            bVal = False
        End If
        FileClose(2)

        IsColLine = bVal
    End Function

    Private Function IsRowLine(ByVal vTmpCol As Object, ByVal vTmpRow As Object, ByVal k As Integer, ByVal iSta As Integer, ByVal iEnd As Integer, ByVal dTol As Double) As Boolean
        'IsRowLine = ct.IsRowLine(vTmpCol, vTmpRow, k, iSta, iEnd, dTol)
        Dim tmpDir As String = GetTempPath()
        Dim inFile As String = tmpDir & "\magic.in"
        Dim outFile As String = tmpDir & "\magic.out"

        FileOpen(1, inFile, OpenMode.Output)
        Print(1, "IRL" & vbNewLine) ' IsRowLine

        Dim uBnd As Integer = UBound(vTmpCol)
        Print(1, uBnd)

        Dim pDat(3) As Double
        Dim i, j As Integer
        For i = 0 To uBnd
            pDat = vTmpCol(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        uBnd = UBound(vTmpRow)
        Print(1, uBnd)

        For i = 0 To uBnd
            pDat = vTmpRow(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        Print(1, k)
        Print(1, iSta)
        Print(1, iEnd)
        Print(1, dTol)
        FileClose(1)

        Dim exeCmd As String = "MagicLink.exe " & Chr(34) & inFile & Chr(34) & " " & Chr(34) & outFile & Chr(34)
        Shell(exeCmd, AppWinStyle.Hide, True)

        FileOpen(2, outFile, OpenMode.Input)
        Dim iVal As Integer
        Dim bVal As Boolean
        Input(2, iVal)
        If iVal <> 0 Then
            bVal = True
        Else
            bVal = False
        End If
        FileClose(2)

        IsRowLine = bVal
    End Function

    Private Function GetNextLine(ByRef vArr() As Object, ByVal iNum As Integer, ByVal bX As Boolean, ByVal dTol As Double) As Integer
        'GetNextLine = ct.GetNextLine(vArr, iNum, bX, dTol)
        Dim tmpDir As String = GetTempPath()
        Dim inFile As String = tmpDir & "\magic.in"
        Dim outFile As String = tmpDir & "\magic.out"

        FileOpen(1, inFile, OpenMode.Output)
        Print(1, "GNL" & vbNewLine) ' GetNextLine

        Dim uBnd As Integer = UBound(vArr)
        Print(1, uBnd)

        Dim pDat(3) As Double
        Dim i, j As Integer
        For i = 0 To uBnd
            pDat = vArr(i)
            For j = 0 To 3
                Print(1, pDat(j))
            Next j
        Next i

        Print(1, iNum)
        If bX Then
            Print(1, 1)
        Else
            Print(1, 0)
        End If
        Print(1, dTol)
        FileClose(1)

        Dim exeCmd As String = "MagicLink.exe " & Chr(34) & inFile & Chr(34) & " " & Chr(34) & outFile & Chr(34)
        Shell(exeCmd, AppWinStyle.NormalFocus, True)

        FileOpen(2, outFile, OpenMode.Input)
        Dim iVal As Integer
        Input(2, iVal)
        FileClose(2)

        GetNextLine = iVal
    End Function

    Private Function GetNumberFormat(ByVal sText As String) As String
        'GetNumberFormat = ct.GetNumberFormat(sText)
        Dim str As String
        Dim num As Integer
        Dim i As Integer

        If IsNumeric(sText) Then
            If InStr(sText, ",") > 0 Then
                GetNumberFormat = "#.##0"
            ElseIf InStr(sText, "E") > 0 Then
                GetNumberFormat = "0.00000"
            ElseIf InStr(sText, "e") > 0 Then
                GetNumberFormat = "0.00000"
            ElseIf InStr(sText, ".") > 0 Then
                num = Len(sText) - InStr(sText, ".")
                str = "0."
                For i = 1 To num
                    str = str & "0"
                Next
                GetNumberFormat = str
            Else
                GetNumberFormat = "0"
            End If
        Else
            GetNumberFormat = "@"
        End If
    End Function

    Private Function DeleteEntity(vSSpnt As Object, vSEpnt As Object, sObj As String) As Long
        Dim oSel As GcadSelectionSet
        Dim iGcode(0) As Integer
        Dim vData(0) As Object

        On Error GoTo ErrorHandler

        iGcode(0) = 0
        vData(0) = sObj

        oSel = CreateSelSet("SelDup")
        oSel.Select(gcSelectionSetCrossing, vSSpnt, vSEpnt, iGcode, vData)

        If oSel.Count > 1 Then
            DeleteEntity = DeleteDupEntity(oSel, sObj, False, False, 5)
        Else
            DeleteEntity = 0
        End If

        oSel = Nothing

        Exit Function

ErrorHandler:
        oSel = Nothing
    End Function

    Private Function GetCadText(dSpnt() As Double, dEpnt() As Double, r As Integer, c As Integer, iTmp As Integer) As String
        Dim oSel As GcadSelectionSet
        oSel = CreateSelSet("SelText")

        Dim iGcode(0) As Integer
        Dim vData(0) As Object

        iGcode(0) = 0
        vData(0) = "text,mtext"

        oSel.Select(gcSelectionSetCrossing, dSpnt, dEpnt, iGcode, vData)

        Dim iCnt As Integer
        iCnt = oSel.Count

        Select Case iCnt
            Case 0
                GetCadText = ""
                Exit Function
            Case 1
                '가져온 문자가 한개면
                GetCadText = oSel.Item(0).TextString
                If oSel.Item(0).ObjectName = "AcDbMText" Then
                    'MText는 포맷 삭제
                    GetCadText = UnformatMtext(GetCadText)
                End If
                vMerge(iTmp).Handle = oSel.Item(0).Handle
            Case Else
                '아래는 여러줄 mtext의 여러개는 처리 안했음
                '가져온 문자가 여러개면
                '제일 큰놈 높이를 얻어서
                Dim dLargeH As Double
                dLargeH = GetLargeHeight(oSel)

                '버블소트 위->아래,좌->우(큰놈 높이가 오차범위)
                SortTextTable(oSel, dLargeH)
                iCnt = oSel.Count
                If iCnt > 0 Then
                    Dim i As Integer
                    Dim sSum As String = ""
                    Dim vSpnt As Object
                    Dim vEpnt As Object
                    Dim sItem1 As String   'Item(i)
                    Dim sItem2 As String   'Item(i + 1)

                    With oSel
                        '가져온 문자를 순환하면서
                        For i = 0 To iCnt - 1
                            '처음과 다음 아이템 삽입점담고
                            If i <> iCnt - 1 Then
                                vSpnt = .Item(i).InsertionPoint
                                vEpnt = .Item(i + 1).InsertionPoint
                            Else
                                vSpnt = .Item(i - 1).InsertionPoint
                                vEpnt = .Item(i).InsertionPoint
                            End If

                            '두 아이템 높이차보다 처음 문자 높이가 크면 문자는 거의 동일선상
                            '문자가 90도 회전되어 있는 경우는 .. 현재로선 제외
                            '아래 차후 중복 코드 정리 필요함
                            If Abs(vSpnt(1) - vEpnt(1)) < .Item(i).Height Then
                                If i = 0 Then
                                    sItem1 = .Item(i).TextString
                                    If .Item(i).ObjectName = "AcDbMText" Then
                                        sItem1 = UnformatMtext(sItem1)
                                    End If
                                    sItem2 = .Item(i + 1).TextString
                                    If .Item(i + 1).ObjectName = "AcDbMText" Then
                                        sItem2 = UnformatMtext(sItem2)
                                    End If
                                    sSum = sItem1 & sItem2
                                Else
                                    If i <> iCnt - 1 Then
                                        sItem2 = .Item(i + 1).TextString
                                        If .Item(i + 1).ObjectName = "AcDbMText" Then
                                            sItem2 = UnformatMtext(sItem2)
                                        End If
                                        sSum = sSum & sItem2
                                    End If
                                End If
                                '두 아이템 높이차가 더 크면 문자는 처음 문자 아래에 있다(줄넘김 필요)
                            Else
                                If i = 0 Then
                                    sItem1 = .Item(i).TextString
                                    If .Item(i).ObjectName = "AcDbMText" Then
                                        sItem1 = UnformatMtext(sItem1)
                                    End If
                                    sItem2 = .Item(i + 1).TextString
                                    If .Item(i + 1).ObjectName = "AcDbMText" Then
                                        sItem2 = UnformatMtext(sItem2)
                                    End If
                                    sSum = sItem1 & vbLf & sItem2
                                Else
                                    If i <> iCnt - 1 Then
                                        sItem2 = .Item(i + 1).TextString
                                        If .Item(i + 1).ObjectName = "AcDbMText" Then
                                            sItem2 = UnformatMtext(sItem2)
                                        End If
                                        sSum = sSum & vbLf & sItem2
                                    End If
                                End If
                            End If
                        Next
                        GetCadText = sSum
                    End With
                Else
                    GetCadText = ""
                    Exit Function
                End If
        End Select

        '캐드 문자는 윈도우 문자로 치환
        GetCadText.Replace("%%C", "Ф")
        GetCadText.Replace("%%D", "°")
        GetCadText.Replace("%%P", "±")

        Dim dR As Double
        dR = oSel.Item(0).Rotation

        With vMerge(iTmp)
            If dR = 0 Then
                .TextOrient = -4128
            ElseIf Round(Abs(dR - PI / 2), 1) = 0 Then
                .TextOrient = -4171
            ElseIf Round(Abs(dR - PI * (3 / 2)), 1) = 0 Then
                .TextOrient = -4170
            Else
                .TextOrient = -4128
            End If
            .Handle = oSel.Item(0).Handle
        End With

    End Function

    Private Function SetArrange(bHor As Boolean) As Integer
        SetArrange = 0
        If bHor Then
            Select Case tbl_HorArrange
                Case 0
                    SetArrange = 1
                Case 1
                    SetArrange = -4131
                Case 2
                    SetArrange = -4108
                Case 3
                    SetArrange = -4152
                Case 4
                    SetArrange = 9999
            End Select
        Else
            Select Case tbl_VerArrange
                Case 0
                    SetArrange = 1
                Case 1
                    SetArrange = -4160
                Case 2
                    SetArrange = -4108
                Case 3
                    SetArrange = -4107
            End Select
        End If
    End Function

    Private Sub CheckLine(vTmpCol() As Object, vTmpRow() As Object, dTol As Double)
        Dim vCol() As Object
        Dim vRow() As Object
        ReDim vCol(0)
        ReDim vRow(0)

        Dim i As Integer
        Dim k As Integer
        Dim iColMax As Integer
        Dim iRowMax As Integer

        iColMax = UBound(vTmpCol)
        iRowMax = UBound(vTmpRow)

        Dim bExcept As Boolean
        bExcept = False

        If iColMax = 1 And iRowMax = 1 Then
            iRow = 0
            iCol = 0
        Else
            iRow = 0
            iCol = 0

            SortListIN(vTmpCol, dTol)
            SortListZ(vTmpRow, dTol)

            For i = 1 To iColMax - 1
                If Not IsEqual(vTmpCol(i)(0), vTmpCol(i - 1)(0), dTol) Or bExcept Then
                    bExcept = False
                    If Not IsEqual(vTmpCol(i)(0), vTmpCol(iColMax)(0), dTol) Then
                        If (vTmpCol(i)(1) >= vTmpRow(0)(1) And vTmpCol(i)(3) >= vTmpRow(0)(1)) Then
                            bExcept = True
                        ElseIf (vTmpCol(i)(1) <= vTmpRow(iRowMax)(1) And vTmpCol(i)(3) <= vTmpRow(iRowMax)(1)) Then
                            bExcept = True
                        Else
                            iCol = iCol + 1
                            bExcept = False
                        End If
                    End If
                End If
            Next

            For i = 1 To iRowMax - 1
                If Not IsEqual(vTmpRow(i)(1), vTmpRow(i - 1)(1), dTol) Or bExcept Then
                    bExcept = False
                    If Not IsEqual(vTmpRow(i)(1), vTmpRow(iRowMax)(1), dTol) Then
                        If (vTmpCol(0)(0) >= vTmpRow(i)(0) And vTmpCol(0)(0) >= vTmpRow(i)(2)) Then
                            bExcept = True
                        ElseIf (vTmpCol(iColMax)(0) <= vTmpRow(i)(0) And vTmpCol(iColMax)(0) <= vTmpRow(i)(2)) Then
                            bExcept = True
                        Else
                            iRow = iRow + 1
                            bExcept = False
                        End If
                    End If
                End If
            Next
        End If


        Dim c As Integer
        Dim r As Integer
        Dim iColFix As Integer
        Dim iRowFix As Integer

        iColFix = iCol
        iRowFix = iRow
        vCol(0) = vTmpCol(0)
        vRow(0) = vTmpRow(0)

        Dim iSta As Integer
        Dim iEnd As Integer
        Dim bLine As Boolean

        For k = 1 To UBound(vTmpCol)
            iSta = 0
            bLine = False
            For r = 0 To UBound(vTmpRow) - 1
                iEnd = GetNextLine(vTmpRow, iSta, False, dTol)
                If iEnd > iSta Then
                    bLine = IsColLine(vTmpCol, vTmpRow, k, iSta, iEnd, dTol)
                    iSta = iEnd
                End If
                If bLine Then
                    ReDim Preserve vCol(UBound(vCol) + 1)
                    vCol(UBound(vCol)) = vTmpCol(k)
                    Exit For
                End If
            Next
            If Not bLine Then
                If Not IsEqual(vTmpCol(k - 1)(0), vTmpCol(k)(0), dTol) Then
                    If vTmpCol(k)(1) <= vTmpRow(0)(1) And _
                       vTmpCol(k)(3) >= vTmpRow(UBound(vTmpRow))(1) Then
                        iColFix = iColFix - 1
                    End If
                End If
            End If
        Next

        For k = 1 To UBound(vTmpRow)
            iSta = 0
            bLine = False
            For c = 0 To UBound(vTmpCol) - 1
                iEnd = GetNextLine(vTmpCol, iSta, True, dTol)
                If iEnd > iSta Then
                    bLine = IsRowLine(vTmpCol, vTmpRow, k, iSta, iEnd, dTol)
                    iSta = iEnd
                End If
                If bLine Then
                    ReDim Preserve vRow(UBound(vRow) + 1)
                    vRow(UBound(vRow)) = vTmpRow(k)
                    Exit For
                End If
            Next
            If Not bLine Then
                If Not IsEqual(vTmpRow(k - 1)(1), vTmpRow(k)(1), dTol) Then
                    If vTmpCol(0)(0) <= vTmpRow(k)(0) And _
                       vTmpCol(UBound(vTmpCol))(0) >= vTmpRow(k)(2) Then
                        iRowFix = iRowFix - 1
                    End If
                End If
            End If
        Next

        iCol = iColFix
        iRow = iRowFix

        ReDim tbl(iRow, iCol)

        c = 0
        For k = 0 To UBound(vCol)
            iSta = 0
            For r = 0 To iRow
                iEnd = GetNextLine(vRow, iSta, False, dTol)
                If iEnd > iSta Then
                    If IsColLine(vCol, vRow, k, iSta, iEnd, dTol) Then
                        If c <= iCol Then
                            tbl(r, c).LL = 1
                        Else
                            tbl(r, iCol).RL = 1
                        End If
                    Else
                        If c <= iCol Then
                            If Not tbl(r, c).LL = 1 Then tbl(r, c).LL = -4142
                        Else
                            If Not tbl(r, iCol).RL = 1 Then tbl(r, iCol).RL = -4142
                        End If
                    End If

                    If c <= iCol Then
                        tbl(r, c).LX = vCol(k)(0)
                        tbl(r, c).LY = vRow(iSta)(1)
                        tbl(r, c).RX = GetTableRX(vCol, k, dTol)
                        tbl(r, c).RY = GetTableRY(vRow, iSta, dTol)
                    End If
                End If
                iSta = iEnd
            Next

            If k <> UBound(vCol) Then
                If Not IsEqual(vCol(k)(0), vCol(k + 1)(0), dTol) Then
                    c = c + 1
                End If
            End If
        Next

        r = 0
        For k = 0 To UBound(vRow)
            iSta = 0
            For c = 0 To iCol
                iEnd = GetNextLine(vCol, iSta, True, dTol)
                If iEnd > iSta Then
                    If IsRowLine(vCol, vRow, k, iSta, iEnd, dTol) Then
                        If r <= iRow Then
                            tbl(r, c).TL = 1
                        Else
                            tbl(iRow, c).BL = 1
                        End If
                    Else
                        If r <= iRow Then
                            If Not tbl(r, c).TL = 1 Then tbl(r, c).TL = -4142
                        Else
                            If Not tbl(iRow, c).BL = 1 Then tbl(iRow, c).BL = -4142
                        End If
                    End If
                End If
                iSta = iEnd
            Next

            If k <> UBound(vRow) Then
                If Not IsEqual(vRow(k)(1), vRow(k + 1)(1), dTol) Then
                    r = r + 1
                End If
            End If
        Next

        Dim dSpnt(2) As Double
        Dim dEpnt(2) As Double
        ReDim vMerge(0)
        Dim iTmp As Integer
        Dim iER As Integer
        Dim iEC As Integer

        For r = 0 To iRow
            For c = 0 To iCol
                If r = 0 Or Not tbl(r, c).TL = -4142 Then
                    If c = 0 Or c > iEC Then
                        dSpnt(0) = tbl(r, c).LX
                        dSpnt(1) = tbl(r, c).LY
                        iTmp = UBound(vMerge)
                        vMerge(iTmp).SR = r
                        vMerge(iTmp).SC = c
                        If c <> iCol Then
                            If tbl(r, c + 1).LL = -4142 Then
                                For i = c To iCol
                                    If i <> iCol Then
                                        If tbl(r, i + 1).LL = -4142 Then
                                            dEpnt(0) = tbl(r, i + 1).RX
                                        Else
                                            dEpnt(0) = tbl(r, i).RX
                                            iEC = i
                                            Exit For
                                        End If
                                    Else
                                        dEpnt(0) = tbl(r, iCol).RX
                                    End If
                                    iEC = i
                                Next
                            Else
                                dEpnt(0) = tbl(r, c).RX
                                iEC = c
                            End If
                            If r <> iRow Then
                                If tbl(r + 1, c).TL = -4142 Then
                                    For k = r To iRow
                                        If k <> iRow Then
                                            If tbl(k + 1, c).TL = -4142 Then
                                                dEpnt(1) = tbl(k + 1, c).RY
                                            Else
                                                dEpnt(1) = tbl(k, c).RY
                                                iER = k
                                                Exit For
                                            End If
                                        Else
                                            dEpnt(1) = tbl(iRow, c).RY
                                        End If
                                        iER = k
                                    Next
                                Else
                                    dEpnt(1) = tbl(r, c).RY
                                    iER = r
                                End If
                            Else
                                dEpnt(1) = tbl(r, c).RY
                                iER = r
                            End If
                        Else
                            If Not tbl(r, c).LL = -4142 Then
                                dEpnt(0) = tbl(r, iCol).RX
                                iEC = c
                            End If
                            If r <> iRow Then
                                If tbl(r + 1, c).TL = -4142 Then
                                    For k = r To iRow
                                        If k <> iRow Then
                                            If tbl(k + 1, c).TL = -4142 Then
                                                dEpnt(1) = tbl(k + 1, c).RY
                                            Else
                                                dEpnt(1) = tbl(k, c).RY
                                                iER = k
                                                Exit For
                                            End If
                                        Else
                                            dEpnt(1) = tbl(iRow, c).RY
                                        End If
                                        iER = k
                                    Next
                                Else
                                    dEpnt(1) = tbl(r, c).RY
                                    iER = r
                                End If
                            Else
                                dEpnt(1) = tbl(r, c).RY
                                iER = r
                            End If
                        End If 'c <> iCol

                        iTmp = UBound(vMerge)
                        ReDim Preserve vMerge(iTmp + 1)
                        With vMerge(iTmp)
                            .ER = iER
                            .EC = iEC
                            .Text = GetCadText(dSpnt, dEpnt, r, c, iTmp)
                            .TextHAdj = SetArrange(True)
                            .TextVAdj = SetArrange(False)
                        End With

                    End If 'If c = 0 ...Then
                End If 'If r = 0 ...Then
            Next 'iCol

            iEC = 0
            iER = 0
        Next 'iRow

    End Sub

    Private Sub ToExcel(tbl(,) As CadTable)
        Dim oExcel As Object
        Dim oBook As Object
        Dim oSheet As Object
        Dim oTmpCell As Object
        Dim oCell As Object = Nothing

        On Error Resume Next

        oExcel = GetObject(, "Excel.Application")
        If oExcel Is Nothing Then
            oExcel = CreateObject("Excel.Application")
            oBook = oExcel.Workbooks.Add
            oSheet = oBook.Worksheets.Item(1)
        End If
        If oExcel Is Nothing Then
            Err.Clear()
            MsgBox("Excel을 실행할 수 없습니다.", vbInformation, tbl_Title)
            GoTo ErrorHandler
        End If

        oSheet = oExcel.ActiveSheet
        If oSheet.ProtectContents Then
            MsgBox("시트가 보호되어 있거나," & vbCr & "Excel에 열린 문서가 없습니다.", vbInformation, tbl_Title)
            GoTo ErrorHandler
        End If

        With oExcel
            Dim iState As Integer
            iState = .WindowState

            If iState = -4140 Then
                .WindowState = -4143
            End If

            .Assistant.Visible = False

            .Visible = True
            AppActivate(.Application.Caption)

            oTmpCell = .Application.InputBox("표의 좌측상단이 입력될 셀을 하나만 선택하세요", _
                                                  Title:=tbl_Title, Type:=8, Default:=.Selection.Address)

            If oTmpCell Is Nothing Then
                .WindowState = -4140
                .Application.Visible = True
                AppActivate(.Application.Caption)
                GoTo ErrorHandler
            End If

            If Err.Number = 0 Then
                If oTmpCell.Count > 1 Then
                    oCell = oTmpCell.Range("A1")
                ElseIf oTmpCell.Count = 1 Then
                    oCell = oTmpCell
                End If
            End If
            oTmpCell = Nothing

            .DisplayAlerts = False
        End With

        Dim c As Integer
        Dim r As Integer
        Dim sFormat As String

        r = oCell.Row
        c = oCell.Column

        With oSheet.Range(oSheet.Cells(r, c), oSheet.Cells(iRow + r, iCol + c))
            .Borders(XlBordersIndex.xlDiagonalDown).LineStyle = -4142
            .Borders(XlBordersIndex.xlDiagonalUp).LineStyle = -4142
            .Borders(xlEdgeLeft).LineStyle = -4142
            .Borders(xlEdgeTop).LineStyle = -4142
            .Borders(xlEdgeBottom).LineStyle = -4142
            .Borders(xlEdgeRight).LineStyle = -4142
            .Borders(XlBordersIndex.xlInsideVertical).LineStyle = -4142
            .Borders(XlBordersIndex.xlInsideHorizontal).LineStyle = -4142
            .UnMerge()
            .value = ""
            .NumberFormatLocal = "0"
        End With

        If tbl_ChkTable = True Then
            For c = 0 To iCol
                For r = 0 To iRow
                    With oCell.Offset(r, c)
                        .Borders(xlEdgeLeft).LineStyle = tbl(r, c).LL
                        .Borders(xlEdgeRight).LineStyle = tbl(r, c).RL
                        .Borders(xlEdgeTop).LineStyle = tbl(r, c).TL
                        .Borders(xlEdgeBottom).LineStyle = tbl(r, c).BL

                        If tbl_ChkBound Then
                            If c = 0 Then .Borders(xlEdgeLeft).LineStyle = 1
                            If c = iCol Then .Borders(xlEdgeRight).LineStyle = 1
                            If r = 0 Then .Borders(xlEdgeTop).LineStyle = 1
                            If r = iRow Then .Borders(xlEdgeBottom).LineStyle = 1
                        End If

                    End With
                Next
            Next
        End If

        On Error GoTo ErrorHandler

        r = oCell.Row
        c = oCell.Column

        Dim iXType(3) As Integer
        Dim vXData(3) As Object
        Dim bXdata As Boolean
        Dim sExlName As String
        Dim sBook As String
        Dim oTemp As GcadEntity
        sBook = oExcel.ActiveWorkbook.name
        sBook.Replace(".xls", "")
        sExlName = sBook & "|" & oSheet.name

        bXdata = tbl_ChkXdata
        If bXdata Then
            iXType(0) = 1001
            vXData(0) = APPNAME
            iXType(1) = 1000
            vXData(1) = sExlName 'sBook & "|" & oSheet.Name
            iXType(2) = 1070
            iXType(3) = 1071
        End If

        Dim i As Integer
        If tbl_ChkText = True Then
            For i = 0 To UBound(vMerge) - 1
                With vMerge(i)
                    oSheet.Cells(.SR + r, .SC + c) = .Text

                    '연동이면
                    If bXdata Then
                        If vMerge(i).Handle <> "" Then
                            vXData(2) = .SR + r
                            vXData(3) = .SC + c
                            oTemp = GcadDoc.HandleToObject(vMerge(i).Handle)
                            oTemp.SetXData(iXType, vXData)
                        End If
                    End If

                    With oSheet.Range(oSheet.Cells(.SR + r, .SC + c), oSheet.Cells(.ER + r, .EC + c))
                        sFormat = GetNumberFormat(vMerge(i).Text)
                        If sFormat = "@" Then
                            .NumberFormatLocal = sFormat
                            oSheet.Cells(vMerge(i).SR + r, vMerge(i).SC + c) = vMerge(i).Text
                        Else
                            .NumberFormatLocal = sFormat
                        End If
                        If tbl_ChkNoMerge = False Then
                            .Merge()
                        End If

                        If vMerge(i).TextHAdj <> 1 Then
                            If vMerge(i).TextHAdj = 9999 Then
                                If IsNumeric(vMerge(i).Text) Then
                                    .HorizontalAlignment = -4152
                                Else
                                    .HorizontalAlignment = -4108
                                End If
                            Else
                                .HorizontalAlignment = vMerge(i).TextHAdj
                            End If
                        End If

                        If vMerge(i).TextVAdj <> 1 Then
                            .VerticalAlignment = vMerge(i).TextVAdj
                        End If

                        .Orientation = vMerge(i).TextOrient
                    End With
                End With
            Next
        End If

        If tbl_ChkExpand Then
            For i = 0 To iRow
                oSheet.Rows(i + r).EntireRow.AutoFit()
            Next
            For i = 0 To iCol
                oSheet.Columns(i + c).EntireColumn.AutoFit()
            Next
        End If

        oExcel.DisplayAlerts = True
        oExcel = Nothing
        oBook = Nothing
        oSheet = Nothing
        oCell = Nothing

        Exit Sub

ErrorHandler:
        On Error Resume Next
        oExcel.DisplayAlerts = True
        oExcel = Nothing
        oBook = Nothing
        oSheet = Nothing
        oCell = Nothing

        oExcel.Application.Visible = True
        AppActivate(oExcel.Application.Caption)

        If Err.Number Then
            MsgBox(Err.Description)
            Err.Clear()
        End If
    End Sub

    Public Sub CADToExcel()
        InitLibrary()

        vSSpnt = GcadUtil.GetPoint(, vbCr & "표를 포함하는 한쪽 모서리 선택:")
        If IsNothing(vSSpnt) Then Exit Sub

        GcadUtil.InitializeUserInput(32)
        vSEpnt = GcadUtil.GetCorner(vSSpnt, vbCr & "표를 포함하는 반대쪽 모서리 선택:")
        If IsNothing(vSEpnt) Then Exit Sub

        RegionRULD(vSSpnt, vSEpnt)

        '중복객체 삭제
        '    Dim sObj As String
        '    sObj = "text"
        '    Call DeleteEntity(vSSpnt, vSEpnt, sObj)
        '    sObj = "mtext"
        '    Call DeleteEntity(vSSpnt, vSEpnt, sObj)

        '길이가 0인 객체 삭제
        Call DeleteZeroLine(vSSpnt, vSEpnt)

        Dim oSelLine As GcadSelectionSet
        Dim oSelText As GcadSelectionSet
        oSelLine = CreateSelSet("oSelLine")
        oSelText = CreateSelSet("oSelText")

        Dim iGcode(0) As Integer
        Dim vData(0) As Object

        iGcode(0) = 0
        vData(0) = "line,polyline,lwpolyline"

        oSelLine.Select(gcSelectionSetCrossing, vSSpnt, vSEpnt, iGcode, vData)

        If oSelLine.Count = 0 Then
            GcadUtil.Prompt(vbCr & "에러 : 선택한 영역에 선이 없습니다")
            Exit Sub
        End If

        iGcode(0) = 0
        vData(0) = "text,mtext"

        oSelText.Select(gcSelectionSetCrossing, vSSpnt, vSEpnt, iGcode, vData)

        If oSelText.Count = 0 Then
            If tbl_ChkText Then
                GcadUtil.Prompt(vbCr & "에러 : 선택한 영역에 문자가 없습니다")
                Exit Sub
            End If
        End If


        Dim dTol As Double
        Dim dDiff As Double
        With oSelText.Item(0)
            dTol = .Height / 10.0#
            dDiff = .Height / 10.0#
        End With

        col = New Collection

        '선택한 선들 세로선과 가로선으로 분리
        '휘어진선 제거
        '중복선 제거
        DetachLine(oSelLine, dTol)

        col = Nothing

        '엑셀로 넘기기 위한 행,열 개수판단
        '조각난 셀 정보 반영
        '짧은 직선 제거
        '셀 테두리 구성
        CheckLine(vTmpCol, vTmpRow, dDiff)

        '엑셀로 넘기기
        '항상 외곽선 그리기
        '셀 병합하지 않음 옵션 여기서 결정
        ToExcel(tbl)

        UninitLibrary()

        Exit Sub

ErrorHandler:
        UninitLibrary()

    End Sub

End Class


