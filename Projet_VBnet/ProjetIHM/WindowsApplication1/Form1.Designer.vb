<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class ACCEUIL
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(ACCEUIL))
        Me.LabelNom = New System.Windows.Forms.Label()
        Me.BtnJouer = New System.Windows.Forms.Button()
        Me.BtnOptions = New System.Windows.Forms.Button()
        Me.BtnScores = New System.Windows.Forms.Button()
        Me.BtnQuitter = New System.Windows.Forms.Button()
        Me.ComboBoxNom = New System.Windows.Forms.ComboBox()
        Me.LabelTitre = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'LabelNom
        '
        Me.LabelNom.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.LabelNom.Location = New System.Drawing.Point(12, 9)
        Me.LabelNom.Name = "LabelNom"
        Me.LabelNom.Size = New System.Drawing.Size(153, 33)
        Me.LabelNom.TabIndex = 0
        Me.LabelNom.Text = "Entrez votre nom:"
        Me.LabelNom.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'BtnJouer
        '
        Me.BtnJouer.BackColor = System.Drawing.Color.Transparent
        Me.BtnJouer.Enabled = False
        Me.BtnJouer.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.BtnJouer.ForeColor = System.Drawing.SystemColors.ControlText
        Me.BtnJouer.Location = New System.Drawing.Point(692, 12)
        Me.BtnJouer.Name = "BtnJouer"
        Me.BtnJouer.Size = New System.Drawing.Size(96, 53)
        Me.BtnJouer.TabIndex = 2
        Me.BtnJouer.Text = "Jouer"
        Me.BtnJouer.UseVisualStyleBackColor = False
        '
        'BtnOptions
        '
        Me.BtnOptions.BackColor = System.Drawing.Color.Transparent
        Me.BtnOptions.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.BtnOptions.ForeColor = System.Drawing.SystemColors.ControlText
        Me.BtnOptions.Location = New System.Drawing.Point(692, 317)
        Me.BtnOptions.Name = "BtnOptions"
        Me.BtnOptions.Size = New System.Drawing.Size(96, 53)
        Me.BtnOptions.TabIndex = 3
        Me.BtnOptions.Text = "Options"
        Me.BtnOptions.UseVisualStyleBackColor = False
        '
        'BtnScores
        '
        Me.BtnScores.BackColor = System.Drawing.Color.Transparent
        Me.BtnScores.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.BtnScores.ForeColor = System.Drawing.SystemColors.ControlText
        Me.BtnScores.Location = New System.Drawing.Point(692, 376)
        Me.BtnScores.Name = "BtnScores"
        Me.BtnScores.Size = New System.Drawing.Size(96, 53)
        Me.BtnScores.TabIndex = 4
        Me.BtnScores.Text = "Scores"
        Me.BtnScores.UseVisualStyleBackColor = False
        '
        'BtnQuitter
        '
        Me.BtnQuitter.BackColor = System.Drawing.Color.Transparent
        Me.BtnQuitter.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.BtnQuitter.ForeColor = System.Drawing.SystemColors.ControlText
        Me.BtnQuitter.Location = New System.Drawing.Point(692, 435)
        Me.BtnQuitter.Name = "BtnQuitter"
        Me.BtnQuitter.Size = New System.Drawing.Size(96, 53)
        Me.BtnQuitter.TabIndex = 5
        Me.BtnQuitter.Text = "Quitter"
        Me.BtnQuitter.UseVisualStyleBackColor = False
        '
        'ComboBoxNom
        '
        Me.ComboBoxNom.Font = New System.Drawing.Font("Bernard MT Condensed", 15.75!)
        Me.ComboBoxNom.FormattingEnabled = True
        Me.ComboBoxNom.Location = New System.Drawing.Point(172, 9)
        Me.ComboBoxNom.Name = "ComboBoxNom"
        Me.ComboBoxNom.Size = New System.Drawing.Size(121, 33)
        Me.ComboBoxNom.TabIndex = 6
        '
        'LabelTitre
        '
        Me.LabelTitre.AutoSize = True
        Me.LabelTitre.BackColor = System.Drawing.Color.Transparent
        Me.LabelTitre.Font = New System.Drawing.Font("Chiller", 72.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.LabelTitre.ForeColor = System.Drawing.Color.Red
        Me.LabelTitre.Location = New System.Drawing.Point(273, 201)
        Me.LabelTitre.Name = "LabelTitre"
        Me.LabelTitre.Size = New System.Drawing.Size(274, 111)
        Me.LabelTitre.TabIndex = 7
        Me.LabelTitre.Text = "Memory"
        '
        'ACCEUIL
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackgroundImage = CType(resources.GetObject("$this.BackgroundImage"), System.Drawing.Image)
        Me.ClientSize = New System.Drawing.Size(800, 500)
        Me.Controls.Add(Me.LabelTitre)
        Me.Controls.Add(Me.ComboBoxNom)
        Me.Controls.Add(Me.BtnQuitter)
        Me.Controls.Add(Me.BtnScores)
        Me.Controls.Add(Me.BtnOptions)
        Me.Controls.Add(Me.BtnJouer)
        Me.Controls.Add(Me.LabelNom)
        Me.Name = "ACCEUIL"
        Me.Text = "ACCUEIL"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents LabelNom As Label
    Friend WithEvents BtnJouer As Button
    Friend WithEvents BtnOptions As Button
    Friend WithEvents BtnScores As Button
    Friend WithEvents BtnQuitter As Button
    Friend WithEvents ComboBoxNom As ComboBox
    Friend WithEvents LabelTitre As Label
End Class
