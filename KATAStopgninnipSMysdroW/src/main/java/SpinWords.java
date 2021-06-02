public class SpinWords {

    public String spinWords(String sentence) {
        String[] words = sentence.split(" ");
        String sentenceReversed = "";

        for (String word : words) {
            StringBuilder words1 = new StringBuilder();
            if (word.length() >= 5) {
                words1.append(word);
                sentenceReversed += words1.reverse().append(" ");
            } else {
                sentenceReversed += word + " ";
            }
        }
            return sentenceReversed.trim();
    }

    public static void main(String[] args) {

    }
}
