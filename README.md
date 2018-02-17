# Juce-ValueTree-Example
Playing around with the Juce ValueTree class.

There's a small XML file with four colour entries in it in the repo. The application shows the contents of one of these (a box filled with the colour, its name and its hex colour code).

There's a button to toggle which one is displayed, which just loops around the four entries. 

Another button displays a colour editor. You can use this to edit one of the entries. The colour display component is a ValueTree Listener, and so will pick up on any changes made and repaint itself when an edit is made. 

Todo: 
- Load the XML as a file rather than from the Binary, to allow saving/adding entries.
- make the toggle button show a popup menu with the colours listed (possibly along with swatches).
