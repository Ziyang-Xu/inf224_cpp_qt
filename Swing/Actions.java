import javax.swing.*;
import java.awt.event.ActionEvent;

public class Actions {
    public static class SearchAction extends AbstractAction {
        private static final long serialVersionUID = 1L;
        private MainFrame mainFrame;

        public SearchAction(String name, MainFrame mainFrame) {
            super(name);
            this.mainFrame = mainFrame;
        }

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

    public static class PlayAction extends AbstractAction {
        private static final long serialVersionUID = 1L;
        private MainFrame mainFrame;

        public PlayAction(String name, MainFrame mainFrame) {
            super(name);
            this.mainFrame = mainFrame;
        }

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

    public static class ExitAction extends AbstractAction {
        private static final long serialVersionUID = 1L;
        private MainFrame mainFrame;

        public ExitAction(String name, MainFrame mainFrame) {
            super(name);
            this.mainFrame = mainFrame;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            mainFrame.getClientConnection().close();
            System.exit(0);
        }
    }
}