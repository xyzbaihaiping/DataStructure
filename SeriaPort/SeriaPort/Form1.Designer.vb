<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意:  以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改它。  
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.ComboBox1 = New System.Windows.Forms.ComboBox()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.Button3 = New System.Windows.Forms.Button()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.TextBox2 = New System.Windows.Forms.TextBox()
        Me.CheckBox1 = New System.Windows.Forms.CheckBox()
        Me.CheckBox2 = New System.Windows.Forms.CheckBox()
        Me.Button4 = New System.Windows.Forms.Button()
        Me.Button5 = New System.Windows.Forms.Button()
        Me.TextBox3 = New System.Windows.Forms.TextBox()
        Me.TextBox4 = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Button6 = New System.Windows.Forms.Button()
        Me.Button7 = New System.Windows.Forms.Button()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.CheckBox8 = New System.Windows.Forms.CheckBox()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.TextBox5 = New System.Windows.Forms.TextBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.CheckBox9 = New System.Windows.Forms.CheckBox()
        Me.CheckBox7 = New System.Windows.Forms.CheckBox()
        Me.CheckBox6 = New System.Windows.Forms.CheckBox()
        Me.CheckBox5 = New System.Windows.Forms.CheckBox()
        Me.GroupBox3 = New System.Windows.Forms.GroupBox()
        Me.GroupBox4 = New System.Windows.Forms.GroupBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.CheckBox4 = New System.Windows.Forms.CheckBox()
        Me.CheckBox3 = New System.Windows.Forms.CheckBox()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.SuspendLayout()
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(57, 24)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 0
        Me.Button1.Text = "打开串口"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(138, 24)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(75, 23)
        Me.Button2.TabIndex = 1
        Me.Button2.Text = "关闭串口"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'ComboBox1
        '
        Me.ComboBox1.FormattingEnabled = True
        Me.ComboBox1.Location = New System.Drawing.Point(6, 24)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(45, 20)
        Me.ComboBox1.TabIndex = 2
        '
        'SerialPort1
        '
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(13, 125)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(75, 23)
        Me.Button3.TabIndex = 3
        Me.Button3.Text = "发送数据"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'TextBox1
        '
        Me.TextBox1.BackColor = System.Drawing.Color.White
        Me.TextBox1.Location = New System.Drawing.Point(13, 75)
        Me.TextBox1.Multiline = True
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.ScrollBars = System.Windows.Forms.ScrollBars.Both
        Me.TextBox1.Size = New System.Drawing.Size(200, 42)
        Me.TextBox1.TabIndex = 4
        '
        'TextBox2
        '
        Me.TextBox2.BackColor = System.Drawing.Color.White
        Me.TextBox2.Location = New System.Drawing.Point(234, 51)
        Me.TextBox2.Multiline = True
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.ScrollBars = System.Windows.Forms.ScrollBars.Both
        Me.TextBox2.Size = New System.Drawing.Size(252, 97)
        Me.TextBox2.TabIndex = 5
        '
        'CheckBox1
        '
        Me.CheckBox1.AutoSize = True
        Me.CheckBox1.Location = New System.Drawing.Point(41, 24)
        Me.CheckBox1.Name = "CheckBox1"
        Me.CheckBox1.Size = New System.Drawing.Size(42, 16)
        Me.CheckBox1.TabIndex = 6
        Me.CheckBox1.Text = "DTR"
        Me.CheckBox1.UseVisualStyleBackColor = True
        '
        'CheckBox2
        '
        Me.CheckBox2.AutoSize = True
        Me.CheckBox2.Location = New System.Drawing.Point(161, 24)
        Me.CheckBox2.Name = "CheckBox2"
        Me.CheckBox2.Size = New System.Drawing.Size(42, 16)
        Me.CheckBox2.TabIndex = 7
        Me.CheckBox2.Text = "RTS"
        Me.CheckBox2.UseVisualStyleBackColor = True
        '
        'Button4
        '
        Me.Button4.BackColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.Button4.Location = New System.Drawing.Point(89, 20)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(24, 23)
        Me.Button4.TabIndex = 8
        Me.Button4.UseVisualStyleBackColor = False
        '
        'Button5
        '
        Me.Button5.BackColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.Button5.Location = New System.Drawing.Point(209, 20)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(24, 23)
        Me.Button5.TabIndex = 9
        Me.Button5.UseVisualStyleBackColor = False
        '
        'TextBox3
        '
        Me.TextBox3.BackColor = System.Drawing.Color.White
        Me.TextBox3.Location = New System.Drawing.Point(106, 28)
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.Size = New System.Drawing.Size(76, 21)
        Me.TextBox3.TabIndex = 10
        Me.TextBox3.Text = "2000"
        '
        'TextBox4
        '
        Me.TextBox4.Location = New System.Drawing.Point(106, 66)
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.TextBox4.Size = New System.Drawing.Size(76, 21)
        Me.TextBox4.TabIndex = 11
        Me.TextBox4.Text = "50"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(23, 34)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(65, 12)
        Me.Label1.TabIndex = 12
        Me.Label1.Text = "设定周期："
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(23, 71)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(77, 12)
        Me.Label2.TabIndex = 13
        Me.Label2.Text = "设定占空比："
        '
        'Button6
        '
        Me.Button6.BackColor = System.Drawing.SystemColors.ControlLightLight
        Me.Button6.Location = New System.Drawing.Point(322, 29)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(25, 23)
        Me.Button6.TabIndex = 14
        Me.Button6.UseVisualStyleBackColor = False
        '
        'Button7
        '
        Me.Button7.BackColor = System.Drawing.SystemColors.ControlLightLight
        Me.Button7.Location = New System.Drawing.Point(322, 67)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(25, 23)
        Me.Button7.TabIndex = 15
        Me.Button7.UseVisualStyleBackColor = False
        '
        'GroupBox1
        '
        Me.GroupBox1.BackColor = System.Drawing.Color.Transparent
        Me.GroupBox1.Controls.Add(Me.Button1)
        Me.GroupBox1.Controls.Add(Me.Button2)
        Me.GroupBox1.Controls.Add(Me.ComboBox1)
        Me.GroupBox1.Location = New System.Drawing.Point(12, 12)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(219, 65)
        Me.GroupBox1.TabIndex = 17
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "端口选择"
        '
        'GroupBox2
        '
        Me.GroupBox2.BackColor = System.Drawing.Color.Transparent
        Me.GroupBox2.Controls.Add(Me.CheckBox8)
        Me.GroupBox2.Controls.Add(Me.Label6)
        Me.GroupBox2.Controls.Add(Me.TextBox5)
        Me.GroupBox2.Controls.Add(Me.Label5)
        Me.GroupBox2.Controls.Add(Me.CheckBox9)
        Me.GroupBox2.Controls.Add(Me.CheckBox7)
        Me.GroupBox2.Controls.Add(Me.CheckBox6)
        Me.GroupBox2.Controls.Add(Me.Button3)
        Me.GroupBox2.Controls.Add(Me.TextBox1)
        Me.GroupBox2.Controls.Add(Me.CheckBox5)
        Me.GroupBox2.Controls.Add(Me.TextBox2)
        Me.GroupBox2.Location = New System.Drawing.Point(12, 99)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(492, 154)
        Me.GroupBox2.TabIndex = 18
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "数据传送"
        '
        'CheckBox8
        '
        Me.CheckBox8.AutoSize = True
        Me.CheckBox8.Location = New System.Drawing.Point(110, 129)
        Me.CheckBox8.Name = "CheckBox8"
        Me.CheckBox8.Size = New System.Drawing.Size(72, 16)
        Me.CheckBox8.TabIndex = 15
        Me.CheckBox8.Text = "定时发送"
        Me.CheckBox8.UseVisualStyleBackColor = True
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Font = New System.Drawing.Font("宋体", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label6.Location = New System.Drawing.Point(188, 50)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(24, 16)
        Me.Label6.TabIndex = 14
        Me.Label6.Text = "ms"
        '
        'TextBox5
        '
        Me.TextBox5.Location = New System.Drawing.Point(105, 51)
        Me.TextBox5.Name = "TextBox5"
        Me.TextBox5.Size = New System.Drawing.Size(77, 21)
        Me.TextBox5.TabIndex = 13
        Me.TextBox5.Text = "1000"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(13, 57)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(89, 12)
        Me.Label5.TabIndex = 12
        Me.Label5.Text = "定时发送周期："
        '
        'CheckBox9
        '
        Me.CheckBox9.AutoSize = True
        Me.CheckBox9.Location = New System.Drawing.Point(105, 29)
        Me.CheckBox9.Name = "CheckBox9"
        Me.CheckBox9.Size = New System.Drawing.Size(108, 16)
        Me.CheckBox9.TabIndex = 10
        Me.CheckBox9.Text = "发送时添加换行"
        Me.CheckBox9.UseVisualStyleBackColor = True
        '
        'CheckBox7
        '
        Me.CheckBox7.AutoSize = True
        Me.CheckBox7.Location = New System.Drawing.Point(359, 29)
        Me.CheckBox7.Name = "CheckBox7"
        Me.CheckBox7.Size = New System.Drawing.Size(84, 16)
        Me.CheckBox7.TabIndex = 8
        Me.CheckBox7.Text = "清空接收区"
        Me.CheckBox7.UseVisualStyleBackColor = True
        '
        'CheckBox6
        '
        Me.CheckBox6.AutoSize = True
        Me.CheckBox6.Location = New System.Drawing.Point(234, 29)
        Me.CheckBox6.Name = "CheckBox6"
        Me.CheckBox6.Size = New System.Drawing.Size(84, 16)
        Me.CheckBox6.TabIndex = 7
        Me.CheckBox6.Text = "16进制显示"
        Me.CheckBox6.UseVisualStyleBackColor = True
        '
        'CheckBox5
        '
        Me.CheckBox5.AutoSize = True
        Me.CheckBox5.Location = New System.Drawing.Point(13, 29)
        Me.CheckBox5.Name = "CheckBox5"
        Me.CheckBox5.Size = New System.Drawing.Size(84, 16)
        Me.CheckBox5.TabIndex = 6
        Me.CheckBox5.Text = "16进制发送"
        Me.CheckBox5.UseVisualStyleBackColor = True
        '
        'GroupBox3
        '
        Me.GroupBox3.BackColor = System.Drawing.Color.Transparent
        Me.GroupBox3.Controls.Add(Me.CheckBox1)
        Me.GroupBox3.Controls.Add(Me.Button4)
        Me.GroupBox3.Controls.Add(Me.CheckBox2)
        Me.GroupBox3.Controls.Add(Me.Button5)
        Me.GroupBox3.Location = New System.Drawing.Point(246, 12)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(258, 65)
        Me.GroupBox3.TabIndex = 19
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "电平测试"
        '
        'GroupBox4
        '
        Me.GroupBox4.BackColor = System.Drawing.Color.Transparent
        Me.GroupBox4.Controls.Add(Me.Label4)
        Me.GroupBox4.Controls.Add(Me.Label3)
        Me.GroupBox4.Controls.Add(Me.CheckBox4)
        Me.GroupBox4.Controls.Add(Me.CheckBox3)
        Me.GroupBox4.Controls.Add(Me.Label1)
        Me.GroupBox4.Controls.Add(Me.TextBox3)
        Me.GroupBox4.Controls.Add(Me.Label2)
        Me.GroupBox4.Controls.Add(Me.TextBox4)
        Me.GroupBox4.Controls.Add(Me.Button7)
        Me.GroupBox4.Controls.Add(Me.Button6)
        Me.GroupBox4.Location = New System.Drawing.Point(12, 269)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(492, 104)
        Me.GroupBox4.TabIndex = 20
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "波形发生器"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("宋体", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label4.Location = New System.Drawing.Point(188, 68)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(16, 16)
        Me.Label4.TabIndex = 20
        Me.Label4.Text = "%"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("宋体", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label3.Location = New System.Drawing.Point(188, 33)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(24, 16)
        Me.Label3.TabIndex = 19
        Me.Label3.Text = "ms"
        '
        'CheckBox4
        '
        Me.CheckBox4.AutoSize = True
        Me.CheckBox4.Location = New System.Drawing.Point(253, 71)
        Me.CheckBox4.Name = "CheckBox4"
        Me.CheckBox4.Size = New System.Drawing.Size(42, 16)
        Me.CheckBox4.TabIndex = 18
        Me.CheckBox4.Text = "RTS"
        Me.CheckBox4.UseVisualStyleBackColor = True
        '
        'CheckBox3
        '
        Me.CheckBox3.AutoSize = True
        Me.CheckBox3.Location = New System.Drawing.Point(253, 33)
        Me.CheckBox3.Name = "CheckBox3"
        Me.CheckBox3.Size = New System.Drawing.Size(42, 16)
        Me.CheckBox3.TabIndex = 17
        Me.CheckBox3.Text = "DTR"
        Me.CheckBox3.UseVisualStyleBackColor = True
        '
        'Timer1
        '
        Me.Timer1.Interval = 1000
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.ClientSize = New System.Drawing.Size(524, 374)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.ForeColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.Name = "Form1"
        Me.Text = "串口功能测试"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.GroupBox4.ResumeLayout(False)
        Me.GroupBox4.PerformLayout()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents SerialPort1 As System.IO.Ports.SerialPort
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents CheckBox1 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox2 As System.Windows.Forms.CheckBox
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents Button7 As System.Windows.Forms.Button
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents CheckBox3 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox4 As System.Windows.Forms.CheckBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents CheckBox6 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox5 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox7 As System.Windows.Forms.CheckBox
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents TextBox5 As System.Windows.Forms.TextBox
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents CheckBox9 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox8 As System.Windows.Forms.CheckBox
    Friend WithEvents Timer1 As System.Windows.Forms.Timer

End Class
