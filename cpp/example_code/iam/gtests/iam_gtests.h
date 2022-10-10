/*
   Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
   SPDX-License-Identifier: Apache-2.0
*/

#pragma once
#ifndef S3_EXAMPLES_S3_GTESTS_H
#define S3_EXAMPLES_S3_GTESTS_H

#include <aws/core/Aws.h>
#include <memory>
#include <gtest/gtest.h>

namespace AwsDocTest {

    class IAM_GTests : public testing::Test {
    protected:

        void SetUp() override;

        void TearDown() override;

        static void SetUpTestSuite();

        static void TearDownTestSuite();

        static Aws::String getExistingKey();

        static Aws::String getRole();

        static Aws::String getUser();

        static Aws::String getRolePolicyJSON();

        static Aws::String createAccessKey();

        static Aws::String createRole();

        static Aws::String createUser();

        static Aws::String createPolicy();

        static Aws::String preconditionError();

        static Aws::String samplePolicyARN();

        static void deleteAccessKey(const Aws::String& accessKey);

        static void deleteRole(const Aws::String& role);

        static void deleteUser(const Aws::String& user);

        static void deleteAccountAlias(const Aws::String& accountAlias);

        static void detachRolePolicy(const Aws::String& role, const Aws::String& policyARN);

        // s_clientConfig must be a pointer because the client config must be initialized
        // after InitAPI.
        static std::unique_ptr<Aws::Client::ClientConfiguration> s_clientConfig;

    private:
        static Aws::SDKOptions s_options;

        std::stringbuf  m_coutBuffer;  // Use just to silence cout.
        std::streambuf* m_savedBuffer = nullptr;
        static Aws::String      s_accessKey;
        static Aws::String      s_role;
        static Aws::String      s_userName;
        static Aws::String      s_policyArn;
    };
} // AwsDocTest

#endif //S3_EXAMPLES_S3_GTESTS_H
