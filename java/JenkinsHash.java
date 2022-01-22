public class JenkinsHash{
    private static int hash(String key){
        int key_length = key.length();
        int hash = 0;

        for (int i = 0; i < key_length; i++) { 
            hash += Character.toLowerCase(key.charAt(i));
            hash += (hash << 10);
            hash ^= (hash >>> 6);
        }

        hash += (hash << 3);
        hash ^= (hash >>> 11);
        hash += (hash << 15);

        return hash;
    }

    /**
     * 
     * @return the hash in a hex string
     */
    public static String get_hash_string(String key){

        return Long.toHexString(Integer.toUnsignedLong(hash(key)));
    }

    /**
     * 
     * @return the hash as a unsigned 32bit
     */
    public static Long get_hash_long(String key){
        return Integer.toUnsignedLong(hash(key));
    }
}
