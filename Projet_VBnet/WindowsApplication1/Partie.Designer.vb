<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Partie
    Inherits System.Windows.Forms.Form

    'Form remplace la méthode Dispose pour nettoyer la liste des composants.
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

    'Requise par le Concepteur Windows Form
    Private components As System.ComponentModel.IContainer

    'REMARQUE : la procédure suivante est requise par le Concepteur Windows Form
    'Elle peut être modifiée à l'aide du Concepteur Windows Form.  
    'Ne la modifiez pas à l'aide de l'éditeur de code.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Partie))
        Me.Label1 = New System.Windows.Forms.Label()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.ButtonMélanger = New System.Windows.Forms.Button()
        Me.ButtonPause = New System.Windows.Forms.Button()
        Me.LabelMinuterie = New System.Windows.Forms.Label()
        Me.LabelTemps = New System.Windows.Forms.Label()
        Me.LabelNom = New System.Windows.Forms.Label()
        Me.LabelJoueur = New System.Windows.Forms.Label()
        Me.BtnAbandon = New System.Windows.Forms.Button()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.Label20 = New System.Windows.Forms.Label()
        Me.Label19 = New System.Windows.Forms.Label()
        Me.Label18 = New System.Windows.Forms.Label()
        Me.Label17 = New System.Windows.Forms.Label()
        Me.Label16 = New System.Windows.Forms.Label()
        Me.Label15 = New System.Windows.Forms.Label()
        Me.Label14 = New System.Windows.Forms.Label()
        Me.Label13 = New System.Windows.Forms.Label()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.PanelCartes = New System.Windows.Forms.FlowLayoutPanel()
        Me.TimerRetournement = New System.Windows.Forms.Timer(Me.components)
        Me.GroupBox1.SuspendLayout()
        Me.PanelCartes.SuspendLayout()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label1.Image = CType(resources.GetObject("Label1.Image"), System.Drawing.Image)
        Me.Label1.Location = New System.Drawing.Point(3, 0)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(102, 156)
        Me.Label1.TabIndex = 0
        '
        'GroupBox1
        '
        Me.GroupBox1.BackColor = System.Drawing.Color.Gray
        Me.GroupBox1.Controls.Add(Me.ButtonMélanger)
        Me.GroupBox1.Controls.Add(Me.ButtonPause)
        Me.GroupBox1.Controls.Add(Me.LabelMinuterie)
        Me.GroupBox1.Controls.Add(Me.LabelTemps)
        Me.GroupBox1.Controls.Add(Me.LabelNom)
        Me.GroupBox1.Controls.Add(Me.LabelJoueur)
        Me.GroupBox1.Controls.Add(Me.BtnAbandon)
        Me.GroupBox1.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.GroupBox1.Location = New System.Drawing.Point(12, 12)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(776, 62)
        Me.GroupBox1.TabIndex = 1
        Me.GroupBox1.TabStop = False
        '
        'ButtonMélanger
        '
        Me.ButtonMélanger.Location = New System.Drawing.Point(442, 12)
        Me.ButtonMélanger.Name = "ButtonMélanger"
        Me.ButtonMélanger.Size = New System.Drawing.Size(130, 50)
        Me.ButtonMélanger.TabIndex = 6
        Me.ButtonMélanger.Text = "Remélanger"
        Me.ButtonMélanger.UseVisualStyleBackColor = True
        '
        'ButtonPause
        '
        Me.ButtonPause.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.ButtonPause.Location = New System.Drawing.Point(578, 13)
        Me.ButtonPause.Name = "ButtonPause"
        Me.ButtonPause.Size = New System.Drawing.Size(96, 48)
        Me.ButtonPause.TabIndex = 5
        Me.ButtonPause.Text = "Pause"
        Me.ButtonPause.UseVisualStyleBackColor = True
        '
        'LabelMinuterie
        '
        Me.LabelMinuterie.AutoSize = True
        Me.LabelMinuterie.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.LabelMinuterie.Location = New System.Drawing.Point(262, 28)
        Me.LabelMinuterie.Name = "LabelMinuterie"
        Me.LabelMinuterie.Size = New System.Drawing.Size(85, 25)
        Me.LabelMinuterie.TabIndex = 4
        Me.LabelMinuterie.Text = "Minuterie"
        '
        'LabelTemps
        '
        Me.LabelTemps.AutoSize = True
        Me.LabelTemps.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.LabelTemps.Location = New System.Drawing.Point(187, 28)
        Me.LabelTemps.Name = "LabelTemps"
        Me.LabelTemps.Size = New System.Drawing.Size(69, 25)
        Me.LabelTemps.TabIndex = 3
        Me.LabelTemps.Text = "Temps:"
        '
        'LabelNom
        '
        Me.LabelNom.AutoSize = True
        Me.LabelNom.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.LabelNom.Location = New System.Drawing.Point(72, 28)
        Me.LabelNom.Name = "LabelNom"
        Me.LabelNom.Size = New System.Drawing.Size(64, 25)
        Me.LabelNom.TabIndex = 2
        Me.LabelNom.Text = "Joueur"
        '
        'LabelJoueur
        '
        Me.LabelJoueur.AutoSize = True
        Me.LabelJoueur.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.LabelJoueur.Location = New System.Drawing.Point(6, 28)
        Me.LabelJoueur.Name = "LabelJoueur"
        Me.LabelJoueur.Size = New System.Drawing.Size(70, 25)
        Me.LabelJoueur.TabIndex = 1
        Me.LabelJoueur.Text = "Joueur:"
        '
        'BtnAbandon
        '
        Me.BtnAbandon.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.BtnAbandon.Location = New System.Drawing.Point(680, 12)
        Me.BtnAbandon.Name = "BtnAbandon"
        Me.BtnAbandon.Size = New System.Drawing.Size(96, 50)
        Me.BtnAbandon.TabIndex = 0
        Me.BtnAbandon.Text = "Abandon"
        Me.BtnAbandon.UseVisualStyleBackColor = True
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 1000
        '
        'Label20
        '
        Me.Label20.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label20.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label20.Image = CType(resources.GetObject("Label20.Image"), System.Drawing.Image)
        Me.Label20.Location = New System.Drawing.Point(435, 468)
        Me.Label20.Name = "Label20"
        Me.Label20.Size = New System.Drawing.Size(102, 156)
        Me.Label20.TabIndex = 19
        '
        'Label19
        '
        Me.Label19.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label19.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label19.Image = CType(resources.GetObject("Label19.Image"), System.Drawing.Image)
        Me.Label19.Location = New System.Drawing.Point(327, 468)
        Me.Label19.Name = "Label19"
        Me.Label19.Size = New System.Drawing.Size(102, 156)
        Me.Label19.TabIndex = 18
        '
        'Label18
        '
        Me.Label18.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label18.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label18.Image = CType(resources.GetObject("Label18.Image"), System.Drawing.Image)
        Me.Label18.Location = New System.Drawing.Point(219, 468)
        Me.Label18.Name = "Label18"
        Me.Label18.Size = New System.Drawing.Size(102, 156)
        Me.Label18.TabIndex = 17
        '
        'Label17
        '
        Me.Label17.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label17.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label17.Image = CType(resources.GetObject("Label17.Image"), System.Drawing.Image)
        Me.Label17.Location = New System.Drawing.Point(111, 468)
        Me.Label17.Name = "Label17"
        Me.Label17.Size = New System.Drawing.Size(102, 156)
        Me.Label17.TabIndex = 16
        '
        'Label16
        '
        Me.Label16.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label16.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label16.Image = CType(resources.GetObject("Label16.Image"), System.Drawing.Image)
        Me.Label16.Location = New System.Drawing.Point(3, 468)
        Me.Label16.Name = "Label16"
        Me.Label16.Size = New System.Drawing.Size(102, 156)
        Me.Label16.TabIndex = 15
        '
        'Label15
        '
        Me.Label15.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label15.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label15.Image = CType(resources.GetObject("Label15.Image"), System.Drawing.Image)
        Me.Label15.Location = New System.Drawing.Point(435, 312)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(102, 156)
        Me.Label15.TabIndex = 14
        '
        'Label14
        '
        Me.Label14.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label14.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label14.Image = CType(resources.GetObject("Label14.Image"), System.Drawing.Image)
        Me.Label14.Location = New System.Drawing.Point(327, 312)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(102, 156)
        Me.Label14.TabIndex = 13
        '
        'Label13
        '
        Me.Label13.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label13.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label13.Image = CType(resources.GetObject("Label13.Image"), System.Drawing.Image)
        Me.Label13.Location = New System.Drawing.Point(219, 312)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(102, 156)
        Me.Label13.TabIndex = 12
        '
        'Label12
        '
        Me.Label12.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label12.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label12.Image = CType(resources.GetObject("Label12.Image"), System.Drawing.Image)
        Me.Label12.Location = New System.Drawing.Point(111, 312)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(102, 156)
        Me.Label12.TabIndex = 11
        '
        'Label11
        '
        Me.Label11.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label11.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label11.Image = CType(resources.GetObject("Label11.Image"), System.Drawing.Image)
        Me.Label11.Location = New System.Drawing.Point(3, 312)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(102, 156)
        Me.Label11.TabIndex = 10
        '
        'Label10
        '
        Me.Label10.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label10.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label10.Image = CType(resources.GetObject("Label10.Image"), System.Drawing.Image)
        Me.Label10.Location = New System.Drawing.Point(435, 156)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(102, 156)
        Me.Label10.TabIndex = 9
        '
        'Label9
        '
        Me.Label9.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label9.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label9.Image = CType(resources.GetObject("Label9.Image"), System.Drawing.Image)
        Me.Label9.Location = New System.Drawing.Point(327, 156)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(102, 156)
        Me.Label9.TabIndex = 8
        '
        'Label8
        '
        Me.Label8.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label8.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label8.Image = CType(resources.GetObject("Label8.Image"), System.Drawing.Image)
        Me.Label8.Location = New System.Drawing.Point(219, 156)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(102, 156)
        Me.Label8.TabIndex = 7
        '
        'Label7
        '
        Me.Label7.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label7.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label7.Image = CType(resources.GetObject("Label7.Image"), System.Drawing.Image)
        Me.Label7.Location = New System.Drawing.Point(111, 156)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(102, 156)
        Me.Label7.TabIndex = 6
        '
        'Label6
        '
        Me.Label6.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label6.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label6.Image = CType(resources.GetObject("Label6.Image"), System.Drawing.Image)
        Me.Label6.Location = New System.Drawing.Point(3, 156)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(102, 156)
        Me.Label6.TabIndex = 5
        '
        'Label5
        '
        Me.Label5.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label5.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label5.Image = CType(resources.GetObject("Label5.Image"), System.Drawing.Image)
        Me.Label5.Location = New System.Drawing.Point(435, 0)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(102, 156)
        Me.Label5.TabIndex = 4
        '
        'Label4
        '
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label4.Image = CType(resources.GetObject("Label4.Image"), System.Drawing.Image)
        Me.Label4.Location = New System.Drawing.Point(327, 0)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(102, 156)
        Me.Label4.TabIndex = 3
        '
        'Label3
        '
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label3.Image = CType(resources.GetObject("Label3.Image"), System.Drawing.Image)
        Me.Label3.Location = New System.Drawing.Point(219, 0)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(102, 156)
        Me.Label3.TabIndex = 2
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 26.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label2.Image = CType(resources.GetObject("Label2.Image"), System.Drawing.Image)
        Me.Label2.Location = New System.Drawing.Point(111, 0)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(102, 156)
        Me.Label2.TabIndex = 1
        '
        'PanelCartes
        '
        Me.PanelCartes.Controls.Add(Me.Label1)
        Me.PanelCartes.Controls.Add(Me.Label2)
        Me.PanelCartes.Controls.Add(Me.Label3)
        Me.PanelCartes.Controls.Add(Me.Label4)
        Me.PanelCartes.Controls.Add(Me.Label5)
        Me.PanelCartes.Controls.Add(Me.Label6)
        Me.PanelCartes.Controls.Add(Me.Label7)
        Me.PanelCartes.Controls.Add(Me.Label8)
        Me.PanelCartes.Controls.Add(Me.Label9)
        Me.PanelCartes.Controls.Add(Me.Label10)
        Me.PanelCartes.Controls.Add(Me.Label11)
        Me.PanelCartes.Controls.Add(Me.Label12)
        Me.PanelCartes.Controls.Add(Me.Label13)
        Me.PanelCartes.Controls.Add(Me.Label14)
        Me.PanelCartes.Controls.Add(Me.Label15)
        Me.PanelCartes.Controls.Add(Me.Label16)
        Me.PanelCartes.Controls.Add(Me.Label17)
        Me.PanelCartes.Controls.Add(Me.Label18)
        Me.PanelCartes.Controls.Add(Me.Label19)
        Me.PanelCartes.Controls.Add(Me.Label20)
        Me.PanelCartes.Location = New System.Drawing.Point(133, 80)
        Me.PanelCartes.Name = "PanelCartes"
        Me.PanelCartes.Size = New System.Drawing.Size(541, 627)
        Me.PanelCartes.TabIndex = 0
        '
        'TimerRetournement
        '
        Me.TimerRetournement.Interval = 1500
        '
        'Partie
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.ClientSize = New System.Drawing.Size(800, 718)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.PanelCartes)
        Me.Name = "Partie"
        Me.Text = "Partie"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.PanelCartes.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents Label1 As Label
    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents BtnAbandon As Button
    Friend WithEvents LabelNom As Label
    Friend WithEvents LabelJoueur As Label
    Friend WithEvents LabelMinuterie As Label
    Friend WithEvents LabelTemps As Label
    Friend WithEvents Timer1 As Timer
    Friend WithEvents Label20 As Label
    Friend WithEvents Label19 As Label
    Friend WithEvents Label18 As Label
    Friend WithEvents Label17 As Label
    Friend WithEvents Label16 As Label
    Friend WithEvents Label15 As Label
    Friend WithEvents Label14 As Label
    Friend WithEvents Label13 As Label
    Friend WithEvents Label12 As Label
    Friend WithEvents Label11 As Label
    Friend WithEvents Label10 As Label
    Friend WithEvents Label9 As Label
    Friend WithEvents Label8 As Label
    Friend WithEvents Label7 As Label
    Friend WithEvents Label6 As Label
    Friend WithEvents Label5 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents PanelCartes As FlowLayoutPanel
    Friend WithEvents ButtonPause As Button
    Friend WithEvents ButtonMélanger As Button
    Friend WithEvents TimerRetournement As Timer
End Class
