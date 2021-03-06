#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "UiVariables.h"
//#include "MainPanel.h"

class AbstractGraph;
class FastaReader;
class GtfReader;
class GLWidget;

class QAction;
class QLabel;
class QActionGroup;
class QDockWidget;
class QTextEdit;
class QLineEdit;
class QComboBox;
class QPushButton;
class QProgressBar;
class QScrollArea;
class QScrollBar;
class QFrame;
class QTabWidget;
class QCheckBox;
class ViewManager;
class QSignalMapper;

class MainWindow : public QMainWindow
{
    friend class ViewManager;

    Q_OBJECT
public:
    QFrame* glHandler;
    FastaReader* fastaReader;
    GtfReader* trackReader;
    MainWindow();

public slots:
    void showUpdateButton();
    void closeAndUpdateSkittle();
    void removeGraphButton(QAction* presetAction);
    void open();
    void open(QString fileName);
    void updateProgress(int);
    void updateState(QString);
    void updateStatus(QString);
    void changeWindowName(std::string name);
    void openGtf();
    void doubleWidth();
    void halveWidth();
    void addDisplayActions(AbstractGraph*);
    void addDisplayDivider();
    void helpDialog();
    void setGlobalTexture(bool);

    //testing:
    void reportFinished();

signals:
    void newFileOpen(QString name);
    void newGtfFileOpen(QString name);
    void colorSelected(int);

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createUiVars();
    void createActions();
    void createMenus();
    void ensureDocksAreVisible();
    void createDocks();
    void createContextMenus();
    void createToolbars();
    QAction* createColorPalleteAction(QString label, int colorPalletes, QIcon palleteIcon, QActionGroup* group, QSignalMapper *signalMapper);

    void createStatusBar();
    void createUiConnections();
    void createFileConnections();
    bool loadfile(const QString &filename);
    void readSettings();
    void writeSettings();
    void print(const char* str);
    void print(QString);

    UiVariables* ui;
    ViewManager* viewManager;
    QMenu *annotationMenu;
    QMenu *fileMenu;
    QMenu *presetMenu;
    QMenu *searchMenu;
    QMenu *toolMenu;
    QMenu *colorSettingsMenu;
    QMenu *viewMenu;

    QActionGroup *toolActionGroup;
    QActionGroup *colorGroup;

    QToolBar *fileToolBar;
    QToolBar *presetToolBar;
    QToolBar *toolToolBar;
    QToolBar *settingToolBar;

    QDockWidget *infoDock;
    QTextEdit* textArea;
    QTabWidget *tabWidget;

    QPushButton *doubleDisplayWidth;
    QPushButton *halveDisplayWidth;
    QPushButton *zoomExtents;


    QAction *moveAction;
    QAction *resizeAction;
    QAction *zoomAction;
    QAction *selectAction;
    QAction *findAction;
    QAction *screenCaptureAction;

    QAction* updateSkittle;
    //	QAction *browseCommunityAction;
    //	QAction *delAnnotationAction;
    QAction *findSequenceAction;
    QAction *findNextAction;
    QAction *findPrevAction;
    QAction *addViewAction;
    QAction *openAction;
    QAction *openGtfAction;
    QAction *addAnnotationAction;
    QAction *nextAnnotationAction;
    QAction *prevAnnotationAction;

    QAction* textureToggleAction;
    QAction *exitAction;
    QAction *helpAction;
    QAction *aboutQtAct;

    QLabel *statusTip;
    //QProgressBar *processStatus;
    //QLabel *processState;

};

#endif

