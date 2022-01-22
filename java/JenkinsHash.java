public class JenkinsHash{

    private String key = "";
    private int hash = 0;
    private int key_length;


    /**
     * 
     * @param key Key to hash
     */
    public JenkinsHash(String key){
        this.key = key;
        this.key_length = key.length();
        hash();

    }

    private void hash(){
        for (int i = 0; i < key_length; i++) { 
            hash += Character.toLowerCase(key.charAt(i));
            hash += ( hash << 10);
            hash ^= (hash >>> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >>> 11);
        hash += (hash << 15);
    }

    /**
     * 
     * @return the hash in a hex string
     */
    public String get_hash_string(){
        return Long.toHexString(Integer.toUnsignedLong(hash));
    }

    /**
     * 
     * @return the hash as a unsigned 32bit
     */
    public Long get_hash_long(){
        return Integer.toUnsignedLong(hash);
    }

}
