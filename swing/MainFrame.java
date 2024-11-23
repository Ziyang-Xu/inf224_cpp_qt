/**
 * @file MainFrame.java
 * @brief Main application frame for the Swing application.
 */
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;

/**
 * @brief MainFrame class that sets up the main window.
 */
public class MainFrame extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private JTextField searchField;
    private JTextField playField;
    private ClientConnection clientConnection;

    /**
     * @brief Constructor for the MainFrame class.
     */
    public MainFrame() {
        // Set the title of the JFrame
        setTitle("Main Frame Example");

        // Set the default close operation
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Set Nimbus Look and Feel
        try {
            for (UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Create a JTextArea with 10 rows and 30 columns
        textArea = new JTextArea(10, 30);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        textArea.setBorder(new EmptyBorder(10, 10, 10, 10));
        textArea.setFont(new Font("Arial", Font.PLAIN, 14));
        textArea.setPreferredSize(new Dimension(400, 200));

        // Add the JTextArea to a JScrollPane
        JScrollPane scrollPane = new JScrollPane(textArea);

        // Create actions
        Action searchAction = new Actions.SearchAction("Search", this);
        Action playAction = new Actions.PlayAction("Play", this);
        Action exitAction = new Actions.ExitAction("Exit", this);

        // Create a JMenuBar and add a JMenu
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("File");
        menu.add(new JMenuItem(searchAction));
        menu.add(new JMenuItem(playAction));
        menu.add(new JMenuItem(exitAction));
        menuBar.add(menu);
        setJMenuBar(menuBar);

        // Create a JToolBar and add buttons
        JToolBar toolBar = new JToolBar();
        toolBar.add(searchAction);
        toolBar.add(playAction);
        toolBar.add(exitAction);

        // Create a JPanel to hold the buttons and text fields
        JPanel inputPanel = new JPanel(new GridLayout(2, 2, 5, 5));
        searchField = new JTextField();
        playField = new JTextField();
        inputPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        inputPanel.add(new JLabel("Search:"));
        inputPanel.add(searchField);
        inputPanel.add(new JLabel("Play:"));
        inputPanel.add(playField);
        inputPanel.setPreferredSize(new Dimension(400, 100));

        // Add the scroll pane to the center of the JFrame
        add(scrollPane, BorderLayout.CENTER);

        // Add the input panel to the south of the JFrame
        add(inputPanel, BorderLayout.SOUTH);

        // Add the toolbar to the north of the JFrame
        add(toolBar, BorderLayout.NORTH);

        // Pack the components within the JFrame
        pack();

        // Make the JFrame visible
        setVisible(true);

        // Connect to the server
        clientConnection = new ClientConnection("127.0.0.1", 3333);
    }

    public JTextArea getTextArea() {
        return textArea;
    }

    public JTextField getSearchField() {
        return searchField;
    }

    public JTextField getPlayField() {
        return playField;
    }

    public ClientConnection getClientConnection() {
        return clientConnection;
    }

    /**
     * @brief Main method to run the application.
     * @param args Command-line arguments.
     */
    public static void main(String[] args) {
        // For MacOSX menu bar appearance
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        // Create and display the main frame
        SwingUtilities.invokeLater(() -> new MainFrame());
    }
}