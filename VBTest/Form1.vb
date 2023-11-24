Imports Microsoft.Office.Interop
Imports GcadVbaLib

Public Class Form1

    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        'Dim oExcel As Object

        'On Error Resume Next
        'oExcel = GetObject(, "Excel.Application")
        'If oExcel Is Nothing Then
        '    oExcel = CreateObject("Excel.Application")
        'End If
        'oExcel.visible = True

        Dim GcadApp As GcadApplication
        Dim GcadDoc As GcadDocument
        Dim GcadUtil As GcadUtility
        Dim GcadMSp As GcadModelSpace
        Dim GcadCi As GcadCircle
        Dim GcadLyr As GcadLayer
        Dim CurrLyr As GcadLayer
        Dim TextObj As Object
        Dim ARR As Object
        Dim TextStyle As GcadTextStyle
        Dim msg_Error

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
        GcadMSp = GcadDoc.ModelSpace
        TextStyle = GcadDoc.TextStyles.Add("TTEESSTT")
        TextStyle.fontFile = "C:\WINDOWS\Fonts\Gulim.ttc"
        TextStyle.SetFont("돋움체", False, False, 0, 0)
        TextStyle.Height = 0.0#
        TextStyle.Width = 0.8
        GcadDoc.ActiveTextStyle = TextStyle
        GcadApp.Visible = True

        Dim returnPnt1 As Object
        returnPnt1 = GcadUtil.GetPoint(, "select point")
        CurrLyr = GcadDoc.ActiveLayer

        Dim Text1Text As String
        Dim Text2Text As String
        Dim Text3Text As String
        Dim sstt1Text As String
        Dim sstt2Text As String
        Dim sstt3Text As String
        Dim sstt4Text As String
        Dim sstt5Text As String
        Dim sstt6Text As String

        Text1Text = "50"
        Text2Text = "20"
        Text3Text = "원호문자"
        sstt1Text = "4"
        sstt2Text = "3"
        sstt3Text = "2"
        sstt4Text = "2"
        sstt5Text = "2"
        sstt6Text = "10"

        Dim cp(2) As Double
        Dim cisz As Single
        cp(0) = returnPnt1(0) : cp(1) = returnPnt1(1) : cp(2) = returnPnt1(2)
        cisz = Val(Text1Text)

        GcadCi = GcadMSp.AddCircle(cp, cisz)
        ARR = GcadCi.ArrayRectangular(Val(sstt1Text), Val(sstt2Text), Val(sstt3Text), Val(sstt4Text), Val(sstt5Text), Val(sstt6Text))

        TextObj = GcadMSp.AddText(Text3Text, cp, Val(Text2Text))
        TextObj.Alignment = GcAlignment.acAlignmentMiddleCenter
        TextObj.TextAlignmentPoint = cp
        TextObj.StyleName = "tteesstt"
        TextObj.Height = Val(Text2Text)

        GcadDoc.ActiveLayer = CurrLyr
        GcadApp.Update()
    End Sub

End Class
