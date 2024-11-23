/**
 * @file Actions.java
 * @brief Contains action classes for handling user interactions in the Swing application.
 */
import javax.swing.*;
import java.awt.event.ActionEvent;

/**
 * @brief Contains action classes for handling user interactions in the Swing application.
 */
public class Actions {
    /**
     * @brief SearchAction class that handles the search action.
     */
    public static class SearchAction extends AbstractAction {
        private static final long serialVersionUID = 1L;
        private MainFrame mainFrame;

        /**
         * @brief Constructor for the SearchAction class.
         * @param name The name of the action.
         * @param mainFrame The main frame of the application.
         */
        public SearchAction(String name, MainFrame mainFrame) {
            super(name);
            this.mainFrame = mainFrame;
        }

        /**
         * @brief Performs the search action.
         * @param e The action event.
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            String query = mainFrame.getSearchField().getText();
            if (!query.isEmpty()) {
                mainFrame.getClientConnection().sendMessage("search " + query);
                String response = mainFrame.getClientConnection().receiveMessage();
                mainFrame.getTextArea().append("Search Result:\n" + response + "\n");
            }
        }
    }

    /**
     * @brief PlayAction class that handles the play action.
     */
    public static class PlayAction extends AbstractAction {
        private static final long serialVersionUID = 1L;
        private MainFrame mainFrame;

        /**
         * @brief Constructor for the PlayAction class.
         * @param name The name of the action.
         * @param mainFrame The main frame of the application.
         */
        public PlayAction(String name, MainFrame mainFrame) {
            super(name);
            this.mainFrame = mainFrame;
        }

        /**
         * @brief Performs the play action.
         * @param e The action event.
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            String query = mainFrame.getPlayField().getText();
            if (!query.isEmpty()) {
                mainFrame.getClientConnection().sendMessage("play " + query);
                String response = mainFrame.getClientConnection().receiveMessage();
                mainFrame.getTextArea().append("Play Result:\n" + response + "\n");
            }
        }
    }

    /**
     * @brief ExitAction class that handles the exit action.
     */
    public static class ExitAction extends AbstractAction {
        private static final long serialVersionUID = 1L;
        private MainFrame mainFrame;

        /**
         * @brief Constructor for the ExitAction class.
         * @param name The name of the action.
         * @param mainFrame The main frame of the application.
         */
        public ExitAction(String name, MainFrame mainFrame) {
            super(name);
            this.mainFrame = mainFrame;
        }

        /**
         * @brief Performs the exit action.
         * @param e The action event.
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            mainFrame.getClientConnection().close();
            System.exit(0);
        }
    }
}