package tissotFramework.view;

import javax.microedition.lcdui.TextField;

/** @author André Augusto Tissot */
public class FormDateTextField extends TextField {

    public String formatedText;

    public FormDateTextField(String label, String text, int maxSize, int constraints) {
        super(label, text, maxSize, constraints);
        formatedText = text;
    }

    public void setText(String text) {
        formatedText = text;
    }

    public String getText() {
        return formatedText;
    }

    public void applyMask() {
        if (!this.getString().equals(formatedText) && this.getString().length() >= formatedText.length()) {
            for (int i = 0; this.size() > i; i++) {
                if (i == 2 || i == 5) {
                    char[] characters = this.getString().toCharArray();
                    char oldChar = characters[i];
                    characters[i] = '/';
                    if (this.size() == i + 1) {
                        this.setString(String.valueOf(characters) + oldChar);
                    } else {
                        this.setString(String.valueOf(characters));
                    }
                } else {
                    StringBuffer right_format = new StringBuffer(this.getString());
                    if (this.getString().length() == 2 || this.getString().length() == 5) {
                        right_format = new StringBuffer(this.getString() + "/");
                    }
                    if (!Character.isDigit(this.getString().charAt(i))) {
                        StringBuffer newValue = new StringBuffer("");
                        char[] char_array = this.getString().toCharArray();
                        for (int c = 0; c < (this.getString().length()); c++) {
                            if (c != i) {
                                newValue.append(String.valueOf(char_array[c]));
                            }
                        }
                        right_format = newValue;
                    }
                    int[] max_value_of_days_by_month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                    if (right_format.length() > 9 && (Integer.parseInt(right_format.toString().substring(6, right_format.length())) % 4) != 0) {
                        max_value_of_days_by_month[1] = 28;
                    }
                    String right_formats = right_format.toString();
                    if (right_formats.length() > 4 && Character.isDigit(right_formats.charAt(3)) && Character.isDigit(right_formats.charAt(4))) {
                        if (12 < Integer.parseInt(right_formats.toString().substring(3, 5))) {
                            right_formats = right_formats.substring(0, 2) + "/12/" + ((right_formats.length() > 6) ? right_formats.substring(6, right_formats.length()) : "");
                        }
                        if (Character.isDigit(right_formats.charAt(0)) && Character.isDigit(right_formats.charAt(1)) && max_value_of_days_by_month[Integer.parseInt(right_formats.substring(3, 5)) - 1] < Integer.parseInt(right_formats.substring(0, 2))) {
                            right_formats = String.valueOf(max_value_of_days_by_month[Integer.parseInt(right_formats.substring(3, 5)) - 1]) + "/" + ((right_formats.length() > 3) ? right_formats.substring(3, right_formats.length()) : "");
                        }
                    } else if (right_formats.length() > 1 && Character.isDigit(right_formats.charAt(0)) && Character.isDigit(right_formats.charAt(1)) && 31 < Integer.parseInt(right_formats.substring(0, 2))) {
                        right_formats = "31/" + ((right_formats.length() > 3) ? right_formats.substring(3, right_formats.length()) : "");
                    }
                    this.setString(right_formats);
                }
            }
            this.formatedText = this.getString();
        }
    }
}
