Imports System.Windows.Forms
Imports System.IO
Imports GcadVbaLib

<ComClass(MagicInsert.ClassId, MagicInsert.InterfaceId, MagicInsert.EventsId)> _
Public Class MagicInsert

#Region "COM GUID"
    ' 다음 GUID는 이 클래스의 COM ID와 COM 인터페이스를 
    ' 제공합니다. 이 GUID를 변경하면 기존 클라이언트가 해당 
    ' 클래스에 더 이상 액세스할 수 없게 됩니다.
    Public Const ClassId As String = "7ce7362a-ccbe-4047-ba43-b295b729f900"
    Public Const InterfaceId As String = "2d7dc721-6981-498a-943c-53a69d7fa105"
    Public Const EventsId As String = "8b9f4bd2-9a69-4068-9957-91459ca7e96d"
#End Region

    ' 생성 가능한 COM 클래스에는 매개 변수가 없는 Public Sub New()가 
    ' 포함되어 있어야 합니다. 그렇지 않으면 이 클래스가 
    ' COM 레지스트리에 등록되지 않으며 CreateObject를 
    ' 통해 이 클래스가 생성되지 않습니다.
    Public Sub New()
        MyBase.New()
    End Sub

    Dim ins_Title As String
    Dim ins_DrawList As String
    Dim ins_XrefInsert As Boolean
    Dim ins_AttachedInsert As Boolean
    Dim ins_XrefMode As Integer
    Dim ins_UserLocation As Boolean
    Dim ins_XNum As Integer
    Dim ins_YNum As Integer
    Dim ins_XGap As Double
    Dim ins_YGap As Double
    Dim ins_OnlyScale As Boolean
    Dim ins_XScale As Double
    Dim ins_YScale As Double
    Dim ins_ZScale As Double
    Dim ins_ExplodeAfter As Double

    Const QS_KEY = &H1
    Const QS_MOUSEMOVE = &H2
    Const QS_MOUSEBUTTON = &H4
    Const QS_MOUSE = (QS_MOUSEMOVE Or QS_MOUSEBUTTON)
    Const QS_INPUT = (QS_MOUSE Or QS_KEY)
    Private Declare Function GetQueueStatus Lib "user32" (ByVal fuFlags As Long) As Long


    Public Property Title() As String
        Get
            Title = ins_Title
        End Get
        Set(value As String)
            ins_Title = value
        End Set
    End Property

    Public Property DrawList() As String
        Get
            DrawList = ins_DrawList
        End Get
        Set(value As String)
            ins_DrawList = value
        End Set
    End Property

    Public Property XrefInsert() As Integer
        Get
            XrefInsert = ins_XrefInsert
        End Get
        Set(value As Integer)
            ins_XrefInsert = value
        End Set
    End Property

    Public Property AttachedInsert() As Integer
        Get
            AttachedInsert = ins_AttachedInsert
        End Get
        Set(value As Integer)
            ins_AttachedInsert = value
        End Set
    End Property

    Public Property XrefMode() As Integer
        Get
            XrefMode = ins_XrefMode
        End Get
        Set(value As Integer)
            ins_XrefMode = value
        End Set
    End Property

    Public Property UserLocation() As Boolean
        Get
            UserLocation = ins_UserLocation
        End Get
        Set(value As Boolean)
            ins_UserLocation = value
        End Set
    End Property

    Public Property XNum() As Integer
        Get
            XNum = ins_XNum
        End Get
        Set(value As Integer)
            ins_XNum = value
        End Set
    End Property

    Public Property YNum() As Integer
        Get
            YNum = ins_YNum
        End Get
        Set(value As Integer)
            ins_YNum = value
        End Set
    End Property

    Public Property XGap() As Double
        Get
            XGap = ins_XGap
        End Get
        Set(value As Double)
            ins_XGap = value
        End Set
    End Property

    Public Property YGap() As Double
        Get
            YGap = ins_YGap
        End Get
        Set(value As Double)
            ins_YGap = value
        End Set
    End Property

    Public Property OnlyScale() As Boolean
        Get
            OnlyScale = ins_OnlyScale
        End Get
        Set(value As Boolean)
            ins_OnlyScale = value
        End Set
    End Property

    Public Property XScale() As Double
        Get
            XScale = ins_XScale
        End Get
        Set(value As Double)
            ins_XScale = value
        End Set
    End Property

    Public Property YScale() As Double
        Get
            YScale = ins_YScale
        End Get
        Set(value As Double)
            ins_YScale = value
        End Set
    End Property

    Public Property ZScale() As Double
        Get
            ZScale = ins_ZScale
        End Get
        Set(value As Double)
            ins_ZScale = value
        End Set
    End Property

    Public Property ExplodeAfter() As Boolean
        Get
            ExplodeAfter = ins_ExplodeAfter
        End Get
        Set(value As Boolean)
            ins_ExplodeAfter = value
        End Set
    End Property

    Private Function GetNoPath(ByVal sPath As String) As String
        Dim iPos As Integer
        iPos = InStr(sPath, ":\")
        GetNoPath = Mid(sPath, iPos + 2)
    End Function

    Private Sub PurgeBlock(sName As String)
        On Error Resume Next
        GcadDoc.Blocks.Item(sName).Delete()
        If Err.Number Then
            '퍼지할 수 없거나 블록 없음
            Err.Clear()
        End If
    End Sub

    Private Sub InsertDWG(vPnt As Object, sPath As String, dXsc As Double, _
                          dYsc As Double, dZsc As Double, bOnlySc As Boolean)
        On Error Resume Next
        Dim sType As String
        Dim iCurCnt As Long
        Dim iNewCnt As Long
        sType = LCase(Right$(sPath, 3))

        Dim oBlkRef As GcadBlockReference = Nothing
        Select Case sType
            Case "dwg"
                oBlkRef = WorkSpace.InsertBlock(vPnt, sPath, dXsc, dYsc, dZsc, 0.0#)
            Case "dxf"
                iCurCnt = WorkSpace.Count
                oBlkRef = GcadDoc.Import(sPath, vPnt, dXsc)
        End Select


        Select Case sType
            Case "dwg"
                '        With oBlkRef
                '            If .InsUnitsFactor <> 1 Then
                '                .ScaleEntity .InsertionPoint, 1 / .InsUnitsFactor
                '            End If
                '        End With
                Err.Clear()
                '--------------------------------------------
                On Error GoTo ErrorHandler

                Dim vMin As Object = Nothing
                Dim vMax As Object = Nothing

                '최저점을 삽입점으로 이동
                If ins_UserLocation Then
                    With oBlkRef
                        .GetBoundingBox(vMin, vMax)
                        .Move(vMin, vPnt)
                    End With
                End If

                '폭파
                'bOnlySc=X,Y,Z 축척이 모두 같을때 True : Explode Method사용
                '축척이 모두 다르면 SendCommand사용
                Dim sMsg As String
                If ins_ExplodeAfter = True Then
                    If ins_OnlyScale Then
                        oBlkRef.Explode()
                        oBlkRef.Delete()
                    Else
                        GcadDoc.SetVariable("USERS5", oBlkRef.Handle)
                        sMsg = "_explode (handent(getvar""USERS5""))" & vbCr & vbCr
                        GcadDoc.SendCommand(sMsg)
                    End If
                End If
            Case "dxf"
                iNewCnt = WorkSpace.Count
                Dim i As Long
                Dim vZero As Object
                vZero = ZeroPoint()
                On Error Resume Next
                For i = iCurCnt To iNewCnt
                    WorkSpace.Item(i).Move(vZero, vPnt)
                Next
        End Select

ErrorHandler:
        oBlkRef = Nothing
    End Sub

    Private Sub XrefDWG(sPath As String, sName As String, vPnt As Object, dXsc As Double, _
                        dYsc As Double, dZsc As Double, bOnlySc As Boolean)

        Dim bOverlay As Boolean
        If ins_AttachedInsert = True Then
            bOverlay = False
        Else
            bOverlay = True
        End If

        On Error Resume Next
        Dim oXref As GcadExternalReference
        oXref = WorkSpace.AttachExternalReference(sPath, sName, vPnt, dXsc, dYsc, dZsc, 0.0#, bOverlay)

        '경로없음은 경로를 미리 경로없음으로 만들어 넣으면
        'Xref대상 도면과 같은 폴더에 있는 도면만되므로
        'Xref를 전체 경로로 넣은 후 경로없음으로 만들어줘야한다
        If ins_XrefMode = 2 Then
            oXref.Path = GetNoPath(sPath)
        End If

        '    With oXref
        '        If .InsUnitsFactor <> 1 Then
        '            .ScaleEntity .InsertionPoint, 1 / .InsUnitsFactor
        '        End If
        '    End With
        Err.Clear()
        '--------------------------------------------
        On Error GoTo ErrorHandler

        Dim vMin As Object = Nothing
        Dim vMax As Object = Nothing

        '최저점을 삽입점으로 이동
        If ins_UserLocation Then
            With oXref
                .GetBoundingBox(vMin, vMax)
                .Move(vMin, vPnt)
            End With
        End If

ErrorHandler:
        oXref = Nothing
    End Sub

    ' C:\Temp\22\aa\cc
    ' C:\Temp\22\bb\dd\G130600029-1.dwg
    ' => ..\..\bb\dd\G130600029-1.dwg
    ' D:\PROJECTS\GADAuto\GADDraw\Output
    ' D:\PROJECTS\GADAuto\GADDraw\Output\G120300001.dwg
    ' => .\G120300001.dwg
    ' C:\Temp\22\aa\cc
    ' D:\TEMP\G130600029-2.dwg
    ' => D:\TEMP\G130600029-2.dwg
    Private Function GetRelativePath(ByVal srcDir As String, ByVal dstPath As String) As String
        Dim dstDir As String
        Dim relPath As String
        Dim filName As String
        Dim bgn As Integer
        Dim i As Integer

        i = InStrRev(dstPath, "\")
        dstDir = Left(dstPath, i - 1)
        filName = Right(dstPath, Len(dstPath) - i)

        Dim srcList As String() = Split(srcDir, "\")
        Dim dstList As String() = Split(dstDir, "\")
        Dim n As Integer = UBound(srcList)

        i = 0
        While i <= UBound(srcList) And i <= UBound(dstList)
            If StrComp(srcList(i), dstList(i), CompareMethod.Text) <> 0 Then Exit While
            i = i + 1
        End While
        bgn = i

        If bgn = 0 Then
            relPath = dstPath
        ElseIf bgn <= UBound(srcList) Then
            relPath = ""
            i = bgn
            While i <= UBound(srcList)
                relPath = relPath & "..\"
                i = i + 1
            End While
            i = bgn
            While i <= UBound(dstList)
                relPath = relPath & dstList(i) & "\"
                i = i + 1
            End While
            relPath = relPath & filName
        Else
            relPath = ".\" & filName
        End If

        GetRelativePath = relPath
    End Function

    Public Sub Insert()
        InitLibrary()

        On Error GoTo ErrorHandler

        Dim fileList() As String
        Dim iCnt As Integer

        fileList = Split(ins_DrawList, "|")
        If IsNothing(fileList) Then Exit Sub
        '    iCnt = UBound(fileList)
        '    If iCnt < 1 Then Exit Sub

        Dim sLock As String
        sLock = LockBackUp()

        If ins_XScale = 0 Then ins_XScale = 1
        If ins_YScale = 0 Then ins_YScale = 1
        If ins_ZScale = 0 Then ins_ZScale = 1

        Dim dInsPnt(2) As Double
        Dim vPnt As Object = Nothing

        '원점 삽입
        If ins_UserLocation Then
            '지정간격 삽입
            vPnt = GcadUtil.GetPoint(, vbCr & "삽입 기준점 지정:")
            If IsNothing(vPnt) Then GoTo ErrorHandler
            dInsPnt(0) = vPnt(0)
            dInsPnt(1) = vPnt(1)
            dInsPnt(2) = vPnt(2)
        Else
            dInsPnt(0) = 0.0#
            dInsPnt(1) = 0.0#
            dInsPnt(2) = 0.0#
        End If

        Dim iX As Integer
        Dim iY As Integer
        Dim sPath As String
        Dim sOld As String
        Dim sName As String
        Dim i As Integer
        Dim loc As Integer

        sOld = GcadDoc.GetVariable("USERS5")

        Directory.SetCurrentDirectory(GcadDoc.Path)

        iCnt = UBound(fileList)
        For i = 0 To iCnt
            If GetQueueStatus(QS_INPUT) <> 0 Then Application.DoEvents()

            sPath = fileList(i)

            If ins_UserLocation Then
                If iX = ins_XNum Then
                    iX = 0
                    iY = iY + 1
                End If

                dInsPnt(0) = vPnt(0) + ins_XGap * iX
                dInsPnt(1) = vPnt(1) - ins_YGap * iY
                dInsPnt(2) = vPnt(2)
                iX = iX + 1
            End If

            ' get file name from path
            sName = sPath
            loc = InStrRev(sName, "\")
            If loc >= 0 Then sName = Right(sName, Len(sName) - loc)
            loc = InStr(sName, ".")
            If loc >= 0 Then sName = Left(sName, loc - 1)

            Call PurgeBlock(sName)

            If ins_XrefInsert Then
                Select Case ins_XrefMode
                    Case 1
                        sPath = GetRelativePath(GcadDoc.Path, sPath)
                End Select
                XrefDWG(sPath, sName, dInsPnt, ins_XScale, ins_YScale, ins_ZScale, ins_OnlyScale)
            Else
                InsertDWG(dInsPnt, sPath, ins_XScale, ins_YScale, ins_ZScale, ins_OnlyScale)
            End If
        Next

        GcadDoc.SetVariable("USERS5", sOld)

        UninitLibrary()
        Exit Sub

ErrorHandler:

        On Error Resume Next
        UninitLibrary()
    End Sub

End Class


