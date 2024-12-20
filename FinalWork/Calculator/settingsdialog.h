class SettingsDialog : public QDialog {
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = nullptr);

private:
    void setupUI();
    void loadSettings();
    void saveSettings();

    QSpinBox *fontSizeSpinBox;
    QColorDialog *colorDialog;
    QComboBox *layoutComboBox;
};