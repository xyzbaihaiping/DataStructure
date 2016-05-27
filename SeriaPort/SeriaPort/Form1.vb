Imports System.Threading
Imports System.Security.Permissions

'允许在程序内部各个线程对于窗体控件进行操作
<PermissionSet(SecurityAction.Demand, Name:="FullTrust")> _
<System.Runtime.InteropServices.ComVisibleAttribute(True)> _
Public Class Form1

    Dim thread1, thread2, thread3 As Threading.Thread
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        '允许线程对窗口控件进行操作
        Control.CheckForIllegalCrossThreadCalls = False

        ComboBox1.Items.Clear()

        For Each port As String In My.Computer.Ports.SerialPortNames
            ComboBox1.Items.Add(port)
        Next
        ComboBox1.SelectedIndex = 0

        Button2.Enabled = False
        Button3.Enabled = False
        SerialPort1.Encoding = System.Text.Encoding.GetEncoding(936)

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        '打开串口
        With SerialPort1
            .BaudRate = 9600
            .StopBits = 1
            .DataBits = 8
            .Parity = IO.Ports.Parity.None
            .PortName = ComboBox1.SelectedItem.ToString
        End With
        SerialPort1.Open()
        Button1.Enabled = False
        Button2.Enabled = True
        Button3.Enabled = True
    End Sub
    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        '发送数据
        If TextBox1.Text = "" Then
            MsgBox("不能发送空信息")
        End If

        If CheckBox5.Checked = True Then
            Dim i As Integer
            Dim data As String = TextBox1.Text
            Dim len As Integer = data.Length
            Dim n As Integer = 1

            For i = 0 To len - 1 '计算数组大小
                If data(i) = " " Then
                    n += 1
                End If
            Next

            i = 0
            Dim bufbyte(n) As Byte
            Dim j As Integer
            For j = 1 To len Step 1
                If data(j - 1) = " " Or j = 1 Then
                    If data(j - 1) = " " Then
                        j += 1
                    End If
                    bufbyte(i) = CByte(Val("&H " & Mid(data, j, 2)))
                    i += 1
                    j += 1
                End If
            Next
            If CheckBox9.Checked = True Then '若添加换行
                SerialPort1.Write(bufbyte, 0, n)
                SerialPort1.Write(vbCrLf)
            Else
                SerialPort1.Write(bufbyte, 0, n)
            End If
            Else
                If CheckBox9.Checked = True Then
                SerialPort1.Write(TextBox1.Text & vbCrLf)
            Else
                SerialPort1.Write(TextBox1.Text)
            End If
        End If
    End Sub
    Private Sub CheckBox8_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox8.CheckedChanged
        thread3 = New Threading.Thread(AddressOf StopSend)
        thread3.Start()
    End Sub
    Sub StopSend()
        If CheckBox8.Checked = True Then '定时发送
            While True
                If CheckBox8.Checked = True Then '定时发送
                    If CheckBox5.Checked = True Then '若为16进制发送
                        Dim i As Integer
                        Dim data As String = TextBox1.Text
                        Dim len As Integer = data.Length
                        Dim n As Integer = 1

                        For i = 0 To len - 1 '计算数组大小
                            If data(i) = " " Then
                                n += 1
                            End If
                        Next

                        i = 0
                        Dim bufbyte(n) As Byte
                        Dim j As Integer
                        For j = 1 To len Step 1
                            If data(j - 1) = " " Or j = 1 Then
                                If data(j - 1) = " " Then
                                    j += 1
                                End If
                                bufbyte(i) = CByte(Val("&H " & Mid(data, j, 2)))
                                i += 1
                                j += 1
                            End If
                        Next
                        If CheckBox9.Checked = True Then '若添加换行
                            SerialPort1.Write(bufbyte, 0, n)
                            SerialPort1.Write(" ")
                            Thread.Sleep(Val(TextBox5.Text))
                        Else
                            SerialPort1.Write(bufbyte, 0, n)
                            Thread.Sleep(Val(TextBox5.Text))
                        End If
                    Else
                        If CheckBox9.Checked = True Then
                            SerialPort1.Write(TextBox1.Text & vbCrLf)
                            Thread.Sleep(Val(TextBox5.Text))
                        Else
                            SerialPort1.Write(TextBox1.Text)
                            Thread.Sleep(Val(TextBox5.Text))
                        End If
                    End If
                End If
            End While
        End If
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        '关闭串口
        SerialPort1.Close()
        Button3.Enabled = False
        Button1.Enabled = True
        Button2.Enabled = False
        CheckBox1.Enabled = False
        CheckBox2.Enabled = False
        CheckBox3.Enabled = False
        CheckBox4.Enabled = False
        Button4.BackColor = Color.White
        Button5.BackColor = Color.White
        Button6.BackColor = Color.White
        Button7.BackColor = Color.White

    End Sub

    Private Sub SerialPort1_DataReceived(sender As Object, e As IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        Dim str As String
        If CheckBox6.Checked = False Then
            str = SerialPort1.ReadExisting
            TextBox2.Text += str
        Else
            Dim n As Integer = SerialPort1.BytesToRead '获取缓冲区中字节数
            Dim readbyte(n) As Byte
            Dim i As Integer = 0
            For i = 0 To n
                readbyte(i) = SerialPort1.ReadByte
                str = CStr(Hex(readbyte(i)))
                TextBox2.Text += str
            Next

        End If

    End Sub

    Private Sub CheckBox1_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox1.CheckedChanged
        'DTR
        If CheckBox1.Checked = True Then
            SerialPort1.DtrEnable = True
            Button4.BackColor = Color.Red

        Else
            SerialPort1.DtrEnable = False
            Button4.BackColor = Color.Yellow

        End If
    End Sub

    Private Sub CheckBox2_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox2.CheckedChanged
        'RTS
        If CheckBox2.Checked = True Then
            SerialPort1.RtsEnable = True
            Button5.BackColor = Color.Red

        Else
            SerialPort1.RtsEnable = False
            Button5.BackColor = Color.Yellow
        End If
    End Sub
    Private Sub CheckBox3_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox3.CheckedChanged
        thread1 = New Threading.Thread(AddressOf DTRWaveGenerate)
        thread1.Start()

    End Sub
    Sub DTRWaveGenerate()
        Dim time As Integer '周期
        Dim DutyCycle As Integer '占空比
        Dim timehigh As Integer
        Dim timelower As Integer

        While True
            time = Val(TextBox3.Text)
            DutyCycle = Val(TextBox4.Text) '将字符串转为数字

            If time <= 0 Or DutyCycle <= 0 Then
                TextBox3.Text = 2000
                TextBox4.Text = 50
                time = Val(TextBox3.Text)
                DutyCycle = Val(TextBox4.Text)
            End If

            timehigh = time * DutyCycle / 100
            timelower = time - timehigh
            If CheckBox3.Checked = True Then
                SerialPort1.DtrEnable = True
                Button6.BackColor = Color.Red
                Thread.Sleep(timehigh)
                SerialPort1.DtrEnable = False
                Button6.BackColor = Color.Yellow
                Thread.Sleep(timelower)
            Else
                SerialPort1.DtrEnable = False
                Button6.BackColor = Color.White
            End If
        End While
    End Sub

    Private Sub CheckBox4_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox4.CheckedChanged
        thread2 = New Threading.Thread(AddressOf RTSWaveGenerate)
        thread2.Start()
    End Sub
    Sub RTSWaveGenerate()
        Dim time As Integer '周期
        Dim DutyCycle As Integer '占空比
        Dim timehigh As Integer
        Dim timelower As Integer
        While True
            time = Val(TextBox3.Text)
            DutyCycle = Val(TextBox4.Text) '将字符串转为数字

            If time <= 0 Or DutyCycle <= 0 Then
                TextBox3.Text = 2000
                TextBox4.Text = 50
                time = Val(TextBox3.Text)
                DutyCycle = Val(TextBox4.Text)
            End If

            timehigh = time * DutyCycle / 100
            timelower = time - timehigh
            If CheckBox4.Checked = True Then
                SerialPort1.RtsEnable = True
                Button7.BackColor = Color.Red
                Thread.Sleep(timehigh)
                SerialPort1.RtsEnable = False
                Button7.BackColor = Color.Yellow
                Thread.Sleep(timelower)
            Else
                SerialPort1.RtsEnable = False
                Button7.BackColor = Color.White

            End If
        End While
    End Sub

    Private Sub CheckBox7_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox7.CheckedChanged
        If CheckBox7.Checked = True Then
            TextBox2.Clear()
        End If
    End Sub

    Private Sub break()
        Throw New NotImplementedException
    End Sub

End Class
