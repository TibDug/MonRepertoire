<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Options
    Inherits System.Windows.Forms.Form

    'Form remplace la méthode Dispose pour nettoyer la liste des composants.
    <System.Diagnostics.DebuggerNonUserCode()>
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
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Options))
        Me.LabelTemps = New System.Windows.Forms.Label()
        Me.TextBoxTemps = New System.Windows.Forms.TextBox()
        Me.BtnAbandon = New System.Windows.Forms.Button()
        Me.BtnValider = New System.Windows.Forms.Button()
        Me.BtnAide1 = New System.Windows.Forms.Button()
        Me.GroupBoxDiff = New System.Windows.Forms.GroupBox()
        Me.GroupBoxDiff.SuspendLayout()
        Me.SuspendLayout()
        '
        'LabelTemps
        '
        Me.LabelTemps.AutoSize = True
        Me.LabelTemps.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.LabelTemps.Location = New System.Drawing.Point(6, 28)
        Me.LabelTemps.Name = "LabelTemps"
        Me.LabelTemps.Size = New System.Drawing.Size(122, 25)
        Me.LabelTemps.TabIndex = 0
        Me.LabelTemps.Text = "Temps de jeu:"
        '
        'TextBoxTemps
        '
        Me.TextBoxTemps.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.TextBoxTemps.Location = New System.Drawing.Point(139, 28)
        Me.TextBoxTemps.Name = "TextBoxTemps"
        Me.TextBoxTemps.Size = New System.Drawing.Size(100, 32)
        Me.TextBoxTemps.TabIndex = 1
        '
        'BtnAbandon
        '
        Me.BtnAbandon.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.BtnAbandon.Location = New System.Drawing.Point(692, 435)
        Me.BtnAbandon.Name = "BtnAbandon"
        Me.BtnAbandon.Size = New System.Drawing.Size(96, 53)
        Me.BtnAbandon.TabIndex = 2
        Me.BtnAbandon.Text = "Annuler"
        Me.BtnAbandon.UseVisualStyleBackColor = True
        '
        'BtnValider
        '
        Me.BtnValider.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.BtnValider.Location = New System.Drawing.Point(692, 376)
        Me.BtnValider.Name = "BtnValider"
        Me.BtnValider.Size = New System.Drawing.Size(96, 53)
        Me.BtnValider.TabIndex = 3
        Me.BtnValider.Text = "Valider"
        Me.BtnValider.UseVisualStyleBackColor = True
        '
        'BtnAide1
        '
        Me.BtnAide1.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.BtnAide1.ForeColor = System.Drawing.Color.Black
        Me.BtnAide1.Location = New System.Drawing.Point(245, 28)
        Me.BtnAide1.Name = "BtnAide1"
        Me.BtnAide1.Size = New System.Drawing.Size(32, 32)
        Me.BtnAide1.TabIndex = 4
        Me.BtnAide1.Text = "?"
        Me.BtnAide1.UseVisualStyleBackColor = True
        '
        'GroupBoxDiff
        '
        Me.GroupBoxDiff.BackColor = System.Drawing.Color.Transparent
        Me.GroupBoxDiff.Controls.Add(Me.LabelTemps)
        Me.GroupBoxDiff.Controls.Add(Me.BtnAide1)
        Me.GroupBoxDiff.Controls.Add(Me.TextBoxTemps)
        Me.GroupBoxDiff.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBoxDiff.ForeColor = System.Drawing.SystemColors.ButtonFace
        Me.GroupBoxDiff.Location = New System.Drawing.Point(13, 13)
        Me.GroupBoxDiff.Name = "GroupBoxDiff"
        Me.GroupBoxDiff.Size = New System.Drawing.Size(285, 70)
        Me.GroupBoxDiff.TabIndex = 5
        Me.GroupBoxDiff.TabStop = False
        Me.GroupBoxDiff.Text = "Difficulté"
        '
        'Options
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.ClientSize = New System.Drawing.Size(800, 500)
        Me.Controls.Add(Me.GroupBoxDiff)
        Me.Controls.Add(Me.BtnValider)
        Me.Controls.Add(Me.BtnAbandon)
        Me.Name = "Options"
        Me.Text = "Options"
        Me.GroupBoxDiff.ResumeLayout(False)
        Me.GroupBoxDiff.PerformLayout()
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents LabelTemps As Label
    Friend WithEvents TextBoxTemps As TextBox
    Friend WithEvents BtnAbandon As Button
    Friend WithEvents BtnValider As Button
    Friend WithEvents BtnAide1 As Button
    Friend WithEvents GroupBoxDiff As GroupBox
End Class
