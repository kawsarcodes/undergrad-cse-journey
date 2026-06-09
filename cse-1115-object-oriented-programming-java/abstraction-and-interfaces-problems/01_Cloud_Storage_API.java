/*
Problem(1): Design an interactive cross-platform Cloud Storage engine contract 
            allowing client modules to switch host suppliers seamlessly.
Input 
Initialize AWS and Google Cloud concrete providers inside interface references.
Output
[AWS S3] Uploading user_profile.png to secure bucket space.
[Google Cloud] Uploading user_profile.png to object cluster storage.
*/

interface CloudStorageProvider {
    void uploadBlobFile(String resourceName);
    void purgeBlobFile(String resourceName);
}

class AwsS3Provider implements CloudStorageProvider {
    @Override
    public void uploadBlobFile(String resourceName) {
        System.out.println("[AWS S3] Uploading " + resourceName + " to secure bucket space.");
    }

    @Override
    public void purgeBlobFile(String resourceName) {
        System.out.println("[AWS S3] Evicting asset data from object servers.");
    }
}

class GoogleCloudStorage implements CloudStorageProvider {
    @Override
    public void uploadBlobFile(String resourceName) {
        System.out.println("[Google Cloud] Uploading " + resourceName + " to object cluster storage.");
    }

    @Override
    public void purgeBlobFile(String resourceName) {
        System.out.println("[Google Cloud] Destroying disk reference links across distributed nodes.");
    }
}

public class CloudStorageAPI {
    public static void main(String[] args) {
        // High-level abstraction: Coding to an interface, not an implementation
        CloudStorageProvider networkDrive = new AwsS3Provider();
        networkDrive.uploadBlobFile("user_profile.png");

        networkDrive = new GoogleCloudStorage();
        networkDrive.uploadBlobFile("user_profile.png");
    }
}