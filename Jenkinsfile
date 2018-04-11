pipeline {

  agent {
    docker {
      image 'daixtrose/ubuntu_special'
    }
  }

  stages {

    stage('Inform') {
      steps {
        sh 'pwd; cat /etc/lsb-release; ls -l'
      }
    }

    stage('Git Clone') {
      steps {
        sh 'rm -rf continuous-integration-demo'  
        sh 'git clone --recursive https://github.com/daixtrose/continuous-integration-demo'
      }
    }
      
    stage('CMake') {
      steps {
        sh 'cd continuous-integration-demo && mkdir build && cd build && cmake ..'
      }
    }
    stage('Build') {
      steps {
        sh 'cd continuous-integration-demo/build && make'
      }
    }
    stage('Test') {
      steps {
        sh 'cd continuous-integration-demo/build && make test'
      }
    }
  }
}
