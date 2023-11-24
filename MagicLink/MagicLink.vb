
Module MagicLink
    Public Sub Main(args As String())
        'If args.Length <> 2 Then Exit Sub

        Dim inFile As String = args(0)
        Dim outFile As String = args(1)

        On Error GoTo ErrorHandler

        'ct = .GetInterfaceObject("MagicSub.fncGraph")
        Dim ct As Object = New MagicSub.fncGraph
        Dim func As Object = New MagicSub.fncUtil

        On Error GoTo 0

        FileOpen(1, inFile, OpenMode.Input)
        FileOpen(2, outFile, OpenMode.Output)

        Dim fncName As String = ""
        Input(1, fncName)

        Dim uBnd As Integer
        Dim vCol() As Object
        Dim vRow() As Object
        Dim pDat(3) As Double
        Dim c As Integer
        Dim r As Integer
        Dim k As Integer
        Dim iSta As Integer
        Dim iEnd As Integer
        Dim dTol As Double
        Dim dVal As Double
        Dim bVal As Boolean
        Dim iVal As Integer
        Dim sVal As String
        Dim iNum As Integer
        Dim bX As Boolean
        Dim i, j As Integer

        Select Case fncName
            Case "SLZ"
                Input(1, uBnd)
                ReDim vCol(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vCol(i) = pDat
                Next i

                Input(1, dTol)

                func.SortListZ(vCol, dTol)

                uBnd = UBound(vCol)
                Print(2, uBnd)

                For i = 0 To uBnd
                    pDat = vCol(i)
                    For j = 0 To 3
                        Print(2, pDat(j))
                    Next j
                Next i
            Case "SLN"
                Input(1, uBnd)
                ReDim vCol(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vCol(i) = pDat
                Next i

                Input(1, dTol)

                func.SortListN(vCol, dTol)

                uBnd = UBound(vCol)
                Print(2, uBnd)

                For i = 0 To uBnd
                    pDat = vCol(i)
                    For j = 0 To 3
                        Print(2, pDat(j))
                    Next j
                Next i
            Case "SLI"
                Input(1, uBnd)
                ReDim vCol(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vCol(i) = pDat
                Next i

                Input(1, dTol)

                func.SortListIN(vCol, dTol)

                uBnd = UBound(vCol)
                Print(2, uBnd)

                For i = 0 To uBnd
                    pDat = vCol(i)
                    For j = 0 To 3
                        Print(2, pDat(j))
                    Next j
                Next i
            Case "TRX"
                Input(1, uBnd)
                ReDim vCol(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vCol(i) = pDat
                Next i

                Input(1, c)
                Input(1, dTol)

                dVal = ct.GetTableRX(vCol, c, dTol)

                Print(2, dVal)
            Case "TRY"
                Input(1, uBnd)
                ReDim vRow(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vRow(i) = pDat
                Next i

                Input(1, r)
                Input(1, dTol)

                dVal = ct.GetTableRY(vRow, r, dTol)

                Print(2, dVal)
            Case "ICL"
                Input(1, uBnd)
                ReDim vCol(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vCol(i) = pDat
                Next i

                Input(1, uBnd)
                ReDim vRow(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(3))
                    Next j
                    vRow(i) = pDat
                Next i

                Input(1, k)
                Input(1, iSta)
                Input(1, iEnd)
                Input(1, dTol)

                bVal = ct.IsColLine(vCol, vRow, k, iSta, iEnd, dTol)

                If bVal Then
                    Print(2, 1)
                Else
                    Print(2, 0)
                End If
            Case "IRL"
                Input(1, uBnd)
                ReDim vCol(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vCol(i) = pDat
                Next i

                Input(1, uBnd)
                ReDim vRow(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vRow(i) = pDat
                Next i

                Input(1, k)
                Input(1, iSta)
                Input(1, iEnd)
                Input(1, dTol)

                bVal = ct.IsRowLine(vCol, vRow, k, iSta, iEnd, dTol)

                If bVal Then
                    Print(2, 1)
                Else
                    Print(2, 0)
                End If
            Case "GNL"
                Input(1, uBnd)
                ReDim vCol(uBnd)

                For i = 0 To uBnd
                    For j = 0 To 3
                        Input(1, pDat(j))
                    Next j
                    vCol(i) = pDat
                Next i

                Input(1, iNum)
                Input(1, iVal)
                If iVal <> 0 Then
                    bX = True
                Else
                    bX = False
                End If
                Input(1, dTol)

                iVal = ct.GetNextLine(vCol, iNum, bX, dTol)

                Print(2, iVal)
            Case Else
                MsgBox("Unknown command")
        End Select

        FileClose(1)
        FileClose(2)

ErrorHandler:
        If Err.Number Then
            MsgBox(Err.Description & vbCrLf & vbCrLf & _
                    "MagicSub.dll 로드 에러", vbInformation, "Magic")
            Err.Clear()
        End If

        ct = Nothing
        func = Nothing
    End Sub
End Module
