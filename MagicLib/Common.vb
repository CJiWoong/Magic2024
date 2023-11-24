Imports System.Math
Imports GcadVbaLib

Module Common
    Public GcadApp As GcadApplication
    Public GcadDoc As GcadDocument
    Public GcadUtil As GcadUtility

    Public Sub InitLibrary()
        On Error Resume Next

        GcadApp = GetObject(, "GstarCAD.Application")
        If Err.Number Then
            Err.Clear()
            GcadApp = CreateObject("GstarCAD.Application")
            If Err.Number Then
                MsgBox(Err.Description)
                Exit Sub
            End If
        End If

        GcadDoc = GcadApp.ActiveDocument
        GcadUtil = GcadDoc.Utility

        On Error GoTo 0
    End Sub

    Public Sub UninitLibrary()
        GcadApp = Nothing
        GcadDoc = Nothing
        GcadUtil = Nothing
    End Sub

    Public ReadOnly Property PI() As Double
        Get
            PI = 4.0# * Atan(1.0#)
        End Get
    End Property

    Public Function D2R(ByVal dVal As Double) As Double
        D2R = dVal / 180.0# * PI
    End Function

    Public Function IsEqual(ByVal dValue1, ByVal dValue2, Optional dTol = 0.00000001) As Boolean
        IsEqual = Abs(dValue1 - dValue2) <= dTol
    End Function

    Public ReadOnly Property WorkSpace() As Object
        Get
            With GcadDoc 'Autodesk.AutoCAD.ApplicationServices.Application.DocumentManager.MdiActiveDocument.AcadDocument
                If .GetVariable("CVPORT") = 1 Then
                    WorkSpace = .PaperSpace
                Else
                    WorkSpace = .ModelSpace
                End If
            End With
        End Get
    End Property

    Public Function CreateSelSet(ByVal name As String) As GcadSelectionSet
        On Error Resume Next
        If Not IsNothing(GcadDoc.SelectionSets.Item(name)) Then
            GcadDoc.SelectionSets.Item(name).Delete()
        End If
        On Error GoTo 0

        CreateSelSet = GcadDoc.SelectionSets.Add(name)
    End Function

    Public Function DeleteSpace(ByVal sText As String) As String
        Dim dText As String
        dText = Replace(sText, " ", "")
        DeleteSpace = dText
    End Function

    Public Function LockBackUp() As String
        On Error Resume Next
        Dim colLayers As GcadLayers
        colLayers = GcadDoc.Layers

        Dim i As Integer
        Dim sLayer As String = ""
        For i = 0 To colLayers.Count - 1
            With colLayers.Item(i)
                If .Lock Then
                    .Lock = False
                    sLayer = sLayer & "," & .Name
                End If
            End With
        Next
        LockBackUp = sLayer
    End Function

    Public Sub LockRestore(sLayer As String)
        On Error Resume Next
        Dim vLayer As Object
        Dim i As Integer
        If sLayer <> "" Then
            vLayer = Split(sLayer, ",")
            For i = 0 To UBound(vLayer)
                If vLayer(i) <> "" Then
                    GcadDoc.Layers(vLayer(i)).Lock = True
                End If
            Next
        End If
    End Sub

    Public Function ZeroPoint() As Object
        Dim vRtn(0 To 2) As Double
        vRtn(0) = 0.0#
        vRtn(1) = 0.0#
        vRtn(2) = 0.0#
        ZeroPoint = vRtn
    End Function
End Module
