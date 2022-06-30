class AutocompleteSystem {

    TreeNode root;
    TreeNode nodePivot;
    String inputWord;
    PriorityQueue<Pair<String,Integer>> minHeap;

    public AutocompleteSystem(String[] sentences, int[] times) {
        root = new TreeNode();
        nodePivot = root;
        inputWord = "";

        for(int i=0;i<sentences.length;i++){
            TreeNode node = root;
            for(int j=0;j<sentences[i].length();j++){
                Character c = sentences[i].charAt(j);
                if(!node.map.containsKey(c))
                    node.map.put(c,new TreeNode());
                node = node.map.get(c);
            }
            node.time = times[i];
        }

        minHeap = new PriorityQueue<>((x,y)->{
            String xs = x.getKey();
            String ys = y.getKey();
            if(y.getValue()-x.getValue()!=0){
                return  x.getValue()-y.getValue();
            }else{
                for(int i=0;i<Math.min(xs.length(),ys.length());i++){
                    if(xs.charAt(i)!=ys.charAt(i)){
                        return ys.charAt(i)-xs.charAt(i);
                    }
                }
                return xs.length()>ys.length() ? -1 : 1;
            }
        });
    }

    public List<String> input(char c) {

        List<String> result = new ArrayList<>();
        if(c=='#'){

            nodePivot = root;
            for(int i=0;i<inputWord.length();i++){
                char ch = inputWord.charAt(i);
                if(!nodePivot.map.containsKey(ch)){
                    nodePivot.map.put(ch,new TreeNode());
                }
                nodePivot = nodePivot.map.get(ch);
            }
            if(nodePivot.time!=null){
                nodePivot.time+=1;
            }else{
                nodePivot.time = 1;
            }

            nodePivot = root;
            inputWord ="";
            return result;
        }

        inputWord += String.valueOf(c);
        minHeap.clear();

        if(nodePivot!=null){
            if(!nodePivot.map.containsKey(c)){
                nodePivot = null;
                return result;
            }
            nodePivot = nodePivot.map.get(c);

            dfs(nodePivot,minHeap,inputWord);   

            while(minHeap.size()>0 && result.size()<3){
                result.add(minHeap.poll().getKey());
            }
            Collections.reverse(result);
        }

        return result;
    }

    public void dfs(TreeNode node,PriorityQueue<Pair<String,Integer>> minHeap,String word){
        if(node!=null && node.time!=null){
            minHeap.offer(new Pair(word,node.time));
            if(minHeap.size()>3){
                minHeap.poll();
            }
        }
        for(Map.Entry<Character,TreeNode> entry : node.map.entrySet()){
            dfs(entry.getValue(),minHeap,word+String.valueOf(entry.getKey()));
        }
    }
}


class TreeNode{

    Integer time;

    HashMap<Character,TreeNode> map;

    public TreeNode(){
        map = new HashMap<>();
    }
}